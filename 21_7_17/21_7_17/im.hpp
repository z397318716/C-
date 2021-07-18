 /* 2021年6月7日09:51:56
  * 完成IM项目的所有代码*/ 

#include <cstdio>
#include <iostream>
#include <mysql/mysql.h>
#include <jsoncpp/json/json.h>
#include <mutex>

#include "mongoose.h"

using namespace std;

namespace im{
#define MYSQL_HOST "127.0.0.1"
#define MYSQL_USER "root"
#define MYSQL_PASS ""
#define MYSQL_DB   "im_system"
#define ONLINE     "online"
#define OFFLINE    "offline"
  class TableUser{
    public:
      TableUser()
      :_mysql(NULL){
        // 完成数据库操作的初始化
        // 1.初始化 mysql 操作句柄
        _mysql = mysql_init(NULL);
        if(_mysql == NULL){
          printf("init mysql instance failed!\n");
          exit(-1);
        }
        // 2.连接 mysql 服务器
        if(mysql_real_connect(_mysql, MYSQL_HOST, MYSQL_USER, MYSQL_PASS, MYSQL_DB, 0, NULL, 0) == NULL){
          printf("connect mysql server failed!\n");
          mysql_close(_mysql);
          exit(-1);
        }
        // 3. 设置数据库 字符集--- 初始化工作到这里就截止了
        if(mysql_set_character_set(_mysql, "utf8") != 0){
          printf("set client character failed: [%s]\n", mysql_error(_mysql));
          mysql_close(_mysql);
          exit(-1);
        }
        // 4. 选择要操作的数据库
        //mysql_select_db(_mysql, MYSQL_DB);
        // 5. 执行 SQL 语句

      }
      ~TableUser(){
        // 完成数据库操作句柄的销毁
       if(_mysql)
         mysql_close(_mysql);
      }
      bool Insert(const string &name, const string &passwd){
        // 数据库的插入信息一定发生在 未登录状态
        // 注册新用户, 插入新用户的用户名和密码
#define INSERT_USER "insert tb_user value(NULL, '%s', MD5('%s'), '%s');"
        char tmp_sql[4096] = {0};
        sprintf(tmp_sql, INSERT_USER, name.c_str(), passwd.c_str(), OFFLINE);
        return QuerySql(tmp_sql);

        return true;
      }
      bool Delete(const string &name){
        // 根据用户名 删除 用户信息
#define DELETE_USER "delete from tb_user where name = '%s';"
        char tmp_sql[4096] = {0};
        sprintf(tmp_sql, DELETE_USER, name.c_str());
        return QuerySql(tmp_sql);
      }
      bool UpdateStatus(const string &name, const string &status){
        // 状态更新
#define UPDATE_USER_STATU "update tb_user set status='%s' where name='%s';"
        char tmp_sql[4096] = {0};
        sprintf(tmp_sql, UPDATE_USER_STATU, status.c_str(), name.c_str());
        return QuerySql(tmp_sql);
      }
      bool UpdatePasswd(const string &name, const string &passwd){
        // 修改密码
#define UPDATE_USER_PASS "update tb_user set passwd=MD5('%s') where name='%s';"
        char tmp_sql[4096] = {0};
        sprintf(tmp_sql, UPDATE_USER_PASS, passwd.c_str(), name.c_str());
        return QuerySql(tmp_sql);
      }
      bool SelectOne(const string &name, Json::Value *user){
        // 查询单个用户信息
#define SELECT_USER_ONE "select id,passwd,status from tb_user where name='%s';"
        char tmp_sql[4096] = {0};
        sprintf(tmp_sql, SELECT_USER_ONE, name.c_str());
        // 执行sql 语句与 保存执行查询语句后的 结果集 并非原子操作, 所以需要加锁操作,保证安全性
        _mutex.lock();
        if(QuerySql(tmp_sql) == false){
          _mutex.unlock();
          return false;
        }
        MYSQL_RES *res = mysql_store_result(_mysql);
        _mutex.unlock();
        if(res == NULL){
          printf("select one user store result failed: [%s]\n", mysql_error(_mysql));
          return false;
        }
        int num_row = mysql_num_rows(res);
        if(num_row != 1){
          printf("one user result conut error!\n");
          mysql_free_result(res);
          return false;
        }
        for(int i = 0; i < num_row; ++i){
          MYSQL_ROW row = mysql_fetch_row(res);
          (*user)["id"] = stoi(row[0]);
          (*user)["name"] = name.c_str();
          (*user)["passwd"] = row[1];
          (*user)["status"] = row[2];
        }
        mysql_free_result(res);
        return true;
      }
      bool SelectAll(Json::Value *users){
        // 查询所有用户信息
#define SELECT_USER_ALL "select id,name, passwd,status from tb_user;"
        char tmp_sql[4096] = {0};
        sprintf(tmp_sql, SELECT_USER_ALL);
        // 执行sql 语句与 保存执行查询语句后的 结果集 并非原子操作, 所以需要加锁操作,保证安全性
        _mutex.lock();
        if(QuerySql(tmp_sql) == false){
          _mutex.unlock();
          return false;
        }
        MYSQL_RES *res = mysql_store_result(_mysql);
        _mutex.unlock();
        if(res == NULL){
          printf("select one user store result failed: [%s]\n", mysql_error(_mysql));
          return false;
        }
        int num_row = mysql_num_rows(res);
        for(int i = 0; i < num_row; ++i){
          MYSQL_ROW row = mysql_fetch_row(res);
          Json::Value user;
          user["id"] = stoi(row[0]);
          user["name"] = row[1];
          user["passwd"] = row[2];
          user["status"] = row[3];
          users->append(user);
        }
        mysql_free_result(res);
        return true;
      }
      bool VerifyUser(const string &name, const string &passwd){
        // 登录验证
#define VERIFY_USER "select * from tb_user where name='%s' and passwd=MD5('%s');"
        char tmp_sql[4096] = {0};
        sprintf(tmp_sql, VERIFY_USER, name.c_str(), passwd.c_str());
        _mutex.lock();
        if(QuerySql(tmp_sql) == false){
          _mutex.unlock();
          return false;
        }
        MYSQL_RES *res = mysql_store_result(_mysql);
        _mutex.unlock();
        if(res == NULL){
          printf("verify user store result failed: [%s]\n", mysql_error(_mysql));
          return false;
        }
        int num_row = mysql_num_rows(res);
        if(num_row != 1){
          printf("verify user failed!\n");
          mysql_free_result(res);
          return false;
        }
        mysql_free_result(res);
        return true;
      } 

      bool Exists(const string &name){
        // 判断用户是否存在
#define EXISTS_USER "select * from tb_user where name='%s';"
        char tmp_sql[4096] = {0};
        sprintf(tmp_sql, EXISTS_USER, name.c_str());
        _mutex.lock();
        if(QuerySql(tmp_sql) == false){
          _mutex.unlock();
          return false;
        }
        MYSQL_RES *res = mysql_store_result(_mysql);
        _mutex.unlock();
        if(res == NULL){
          printf("exist user store result failed: [%s]\n", mysql_error(_mysql));
          return false;
        }
        int num_row = mysql_num_rows(res);
        if(num_row != 1){
          printf("This user does not exist!\n");
          mysql_free_result(res);
          return false;
        }
        mysql_free_result(res);
        return true;
      }
    private:
      // 执行SQL语句的函数, 不对外开放
      bool QuerySql(const string &sql){
        if(mysql_query(_mysql, sql.c_str()) != 0){
          printf("query sql: [%s] failed: [%s] \n", sql.c_str(), mysql_error(_mysql));
          return false;
        }
        return true;
      }
    private:
      MYSQL *_mysql;
      mutex _mutex;
  };
  class IM{
    public:
      ~IM(){
        mg_mgr_free(&_mgr);
      }
      static bool Init(const string &port = "9000"){
        _tb_user = new TableUser();
        mg_mgr_init(&_mgr);
        string addr = "0.0.0.0:";
        addr += port;
        _lst_http = mg_http_listen(&_mgr, addr.c_str(), callback, &_mgr);
        if(_lst_http == NULL){
          cout << "http listen failed!\n";
          return false;
        }
        return true;
      }
      static bool Run(){
        while(1){
          mg_mgr_poll(&_mgr, 1000);
        }
        return true;
      }
    private:
      static bool reg(struct mg_connection *c, struct mg_http_message *hm){
        /* 流程:
         * 从正文中(hm->body) 获取到提交的用户信息---json 格式的字符串
         * 解析得到用户名和密码
         * 判断这个用户是否已经被占用
         * 将用户信息插入到数据库中*/
        int status = 200;
        string header = "Content-Type:application/json\r\n";
        //1. 从正文中获取提交的用户信息
        string body;
        body.assign(hm->body.ptr, hm->body.len);
        //2. 解析得到用户名和密码
        Json::Value user;
        Json::Reader reader;
        bool ret = reader.parse(body, user);
        if(ret == false){
          status = 400;
          mg_http_reply(c, status, header.c_str(), "{\"reason\":\"请求格式错误\"}");
          return false;
        }
        //3. 判断这个用户是否已经被占用
       ret = _tb_user->Exists(user["name"].asString());
       if(ret == true){
         status = 400;
         mg_http_reply(c, status, header.c_str(), "{\"reason\":\"用户名被占用\"}");
         return false;
       }
        //3. 将用户信息插入到数据库中
        ret = _tb_user->Insert(user["name"].asString(), user["passwd"].asString());
        if(ret == false){
          status = 500;
          mg_http_reply(c, status, header.c_str(), "{\"reason\":\"数据库访问错误\"}");
          return false;
        }
        mg_http_reply(c, status, header.c_str(), "{\"reason\":\"注册成功\"}");
        return true;
      }
      static bool login(struct mg_connection *c, struct mg_http_message *hm){
        int rsp_status = 200;
        string rsp_body = "{\"reason\":\"登录成功\"}";
        string rsp_header = "Content-Type: application/json\r\n";
        string req_body;
        req_body.assign(hm->body.ptr, hm->body.len);
        Json::Value user;
        Json::Reader reader;
        bool ret = reader.parse(req_body, user);
        if(ret == false){
          rsp_status = 400;
          rsp_body = "{\"reason\":\"请求格式错误\"}";
          mg_http_reply(c, rsp_status, rsp_header.c_str(), rsp_body.c_str());
          return false;
        }
        ret = _tb_user->VerifyUser(user["name"].asString(), user["passwd"].asString());
        if(ret == false){
          rsp_status = 403;
          rsp_body = "{\"reason\":\"用户名或密码错误\"}";
          mg_http_reply(c, rsp_status, rsp_header.c_str(), rsp_body.c_str());
          return false;
        }
        mg_http_reply(c, rsp_status, rsp_header.c_str(), rsp_body.c_str());
        return true;
      }
      static void Broadcast(const string &msg){
        struct mg_connection *c;
        for(c = _mgr.conns; c != NULL; c = c->next){
          if(c->is_websocket){
            mg_ws_send(c, msg.c_str(), msg.size(), WEBSOCKET_OP_TEXT);
          }
        }
        return;
      }
      static void callback(struct mg_connection *c, int ev, void *ev_data, void *fn_data){
        struct mg_http_message *hm = (struct mg_http_message*)ev_data;
        struct mg_ws_message *wm = (struct mg_ws_message*)ev_data;
        switch(ev){
          case MG_EV_HTTP_MSG:
            if(mg_http_match_uri(hm, "/reg")){
              // 注册的提交表单数据请求
              reg(c, hm); // 传入 http 请求信息 和 链接 进行相应的处理
            }else if(mg_http_match_uri(hm, "/login")){
              // 登录的提交表单数据请求
              login(c, hm);
            }else if(mg_http_match_uri(hm, "/websocket")){
              // websocket 的握手请求
             mg_ws_upgrade(c, hm, NULL); 
            }else{
              // 静态页面请求
              struct mg_http_serve_opts opts = {
                .root_dir = "./web_root"
              };
              // 静态资源页面响应
              mg_http_serve_dir(c, hm, &opts);
              
            }
            break;
          case MG_EV_WS_MSG:
            {
              string msg;
              msg.assign(wm->data.ptr, wm->data.len);
              Broadcast(msg);
            }
            break;
          case MG_EV_CLOSE:
            // 
            break;
          default:
            break;
        }
        return;
      }
    private:
      static TableUser *_tb_user;
      string _addr; // 监听地址信息
      static struct mg_mgr _mgr; // 句柄
      static struct mg_connection *_lst_http; // 监听连接

  };
  TableUser *IM::_tb_user = NULL;
  struct mg_mgr IM::_mgr;
  struct mg_connection *IM::_lst_http = NULL;
}
