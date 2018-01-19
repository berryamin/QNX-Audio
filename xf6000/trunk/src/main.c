#include <stdio.h>
#include <unistd.h>
#include "icI2C.h"
#include "vc_ctrl_api.h"

int main ( void )
{
  int32_t ret = -1;
  int millisecond = 0;
  int version = 0;
  int workmode = 0;
  Command_t cmd = {0};

  if ( icI2C_Init() == 0 ) {
    printf ( "I2C init success.\n" );
  }
  usleep ( 2500000 ); // ģ������

  version = VCGetVersion(&cmd);
  printf("Curent version:%d\n",version);

  //VCChangeOutputFormat(&cmd,WORK_MODE_TOPLIGHT);

  ret = VCChangeWorkMode(&cmd, WORK_MODE_TOPLIGHT);
  if(ret == 0) {
    printf("VCChangeWorkMode() success with WORK_MODE_TOPLIGHT.\n");
  }

  printf("Get work mode.\n");
  workmode = VCGetWorkMode(&cmd);
  printf("Current work mode:%d.\n",workmode);


  // �����л�
  // �ϵ��������л���¼�����ܡ�һ�㲻����ʶ��ͻ���ʱ����ʹ��ģ���¼�����ܡ�
  ret = VCChangeFunc ( &cmd, FUNC_MODE_PASSBY );
  if(ret == 0) {
    printf("VCChangeFunc() success with FUNC_MODE_PASSBY.\n");
  }
  // ����ʶ��ǰ�л������빦��
  ret = VCChangeFunc ( &cmd, FUNC_MODE_NOISECLEAN );
  if(ret == 0) {
    printf("VCChangeFunc() success with FUNC_MODE_NOISECLEAN.\n");
  }
#if 0
  // ��������ʱ�л������ѻ�����������
  ret = VCChangeFunc ( &cmd, FUNC_MODE_WAKEUP );
  if(ret == 0) {
    printf("VCChangeFunc() success with FUNC_MODE_WAKEUP.\n");
  }

  while ( 1 ) {
    if ( VCGetWakeupSign ( &cmd, &millisecond ) == 1 ) {
      // ������
      printf("Process Wakeup.\n");
      break;
    }
    printf("Check Wakeup.\n");
    usleep ( 200000 );
  }

  // ��绰ʱ�л����绰�����������ܡ�ͨ���㲻��Ҫ�˹��ܡ�
  // ע����ĵ绰ϵͳ�������˻����������ܡ�����Ҫʹ�����ǵĵ绰����������
  // ��绰ʱ��ֻҪ��ģ���л���¼�����ܼ��ɡ�
  ret = VCChangeFunc ( &cmd, FUNC_MODE_PHONE );

  for ( ;; ) {}
#endif
}
