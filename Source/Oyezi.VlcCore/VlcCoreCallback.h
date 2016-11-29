#ifndef HEAD_H
#define HEAD_H
#include "export_head.h"
#endif

#ifndef VLC_H
#define VLC_H
#include <vlc\vlc.h>
#endif


libvlc_event_manager_t *pVLCMediaPlayerEventManager;          // MediaPlayer�¼�������ָ��
libvlc_event_manager_t *pVLCMediaEventManager;                       // Media �¼�������ָ��

void OnStateChanged(libvlc_state_t state);
void OnVLCEventCallback(const struct libvlc_event_t *pEvent, void * value);



/**
*�����¼��ص��ĺ���ָ������
*���� newCahce ��ǰ����Ľ���
*/
typedef void(*BuffingCallback)(float newCache);
// �����¼��ص�����ָ��
BuffingCallback pfunBuffingCallback;
CoreAPI void AttachBufferingCallback(BuffingCallback pBuffingCallback);

typedef void(*EndedCallback)();
// ���Ž����¼��Ļص�����ָ��
EndedCallback pfunEndedCallback;
CoreAPI void AttachEndedCallback(EndedCallback pEndedCallback);





