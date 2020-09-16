//#include "stdio.h"
//#include "stdlib.h"
//#include "math.h"
//double frand()
//{
//	return 2 * ((rand() / (double)RAND_MAX) - 0.5); // �������
//}
//
//void main()
//{
//	float x_last = 0;
//	float p_last = 0.02;
//	float Q = 0.018;
//	float R = 0.542;
//	float kg;
//	float x_mid;
//	float x_now;
//	float p_mid;
//	float p_now;
//	float z_real = 0.56;//0.56
//	float z_measure;
//	float sumerror_kalman = 0;
//	float sumerror_measure = 0;
//	int i;
//	x_last = z_real + frand()*0.03;
//	x_mid = x_last;
//	for (i = 0; i < 20; i++)
//	{
//		x_mid = x_last;                                     //x_last=x(k-1|k-1),x_mid=x(k|k-1)
//		p_mid = p_last + Q;                                     //p_mid=p(k|k-1),p_last=p(k-1|k-1),Q= ����
//		kg = p_mid / (p_mid + R);                                 //kg Ϊkalman filter ��RΪ����
//		z_measure = z_real + frand()*0.03;                      // ����ֵ
//		x_now = x_mid + kg*(z_measure - x_mid);                   // ���Ƴ�������ֵ
//		p_now = (1 - kg)*p_mid;                                 // ����ֵ��Ӧ��covariance
//		printf("Real position: %6.3f \n", z_real);           // ��ʾ��ֵ
//		printf("Mesaured position: %6.3f [diff:%.3f]\n", z_measure, fabs(z_real - z_measure));
//		// ��ʾ����ֵ�Լ���ֵ�����ֵ֮������
//		printf("Kalman position: %6.3f [diff:%.3f]\n", x_now, fabs(z_real - x_now));  // ��ʾkalman ����ֵ�Լ���ֵ�Ϳ���������ֵ�����
//		sumerror_kalman += fabs(z_real - x_now);            //kalman ����ֵ���ۻ����
//		sumerror_measure += fabs(z_real - z_measure);         // ��ֵ�����ֵ���ۻ����
//		p_last = p_now;                                     // ����covariance ֵ
//		x_last = x_now;                                     // ����ϵͳ״ֵ̬
//	}
//	printf(" ���������� : %f\n", sumerror_measure);     // ��������ۻ����
//	printf(" ���忨�����˲����: %f\n", sumerror_kalman);  // ���kalman �ۻ����
//	printf(" �����������ռ����: %d%% \n", 100 - (int)((sumerror_kalman / sumerror_measure) * 100));
//	return 0;
//}
