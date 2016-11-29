/*****************************************************************************
*VlcCore.h : �����Ҫ�ĺ���ָ������ ������������������
*****************************************************************************
*     ������:          liuyuan      QQ:991258519
* github��ַ:          leoualy/Oyezi.MediaPlayer
*   ��������:          2016/11/27
*
*      ����:           ��DLL��װ��VLC�ĵײ�⣬C/C++����ֱ�ӵ��ã�C#ͨ��������Ҳ����ʹ��
*                      Ŀǰ�汾ֻ��Ϊ�˿���ʵ����Ŀ��Ҫ�Ĺ��ܣ���Ҫ����ͨ��http����������Ƶ
*                      �������Ĳ�����ͣ�⣬�����˻����¼��Ļص�����ָ�����ͣ�.net ƽ̨����ͨ��
*                      ����ȼ۵�ί�к��¼�����.net �Ĵ�����������ע��
*                      Ŀǰ����ṹ�Ƚϼ�ª�������������󡣽�����������ḻ���ܣ������ṹ���ȶ���
*      ����1��
                     ���ڣ�2016/11/30
					 ���ݣ�ÿ��Play()������ʹ��Ƶ�ӿ�ʼ����
					              �������Ƶ�����¼������Դ��ⲿע����Ƶ�����Ļص�������
*
*
*****************************************************************************/

#include<Windows.h>
#include<regex>

#ifndef VLC_H
#define VLC_H
#include <vlc\vlc.h>
#endif

#ifndef HEAD_H
#define HEAD_H
#include "export_head.h"
#endif

libvlc_instance_t *pVLCInstance;                                     // libvlc ʵ��ָ��
libvlc_media_player_t *pVLCMediaPlayer;                  // mediaPlayer ʵ��ָ��
libvlc_media_t *pVLCMedia;

extern void OnVLCEventCallback(const struct libvlc_event_t *pEvent, void * value);

// Ϊmedia����¼�
extern void attach_media_events(libvlc_media_t *pMedia);
// Ϊmedia_player����¼�
extern void attach_media_player_events(libvlc_media_player_t *pMediaPlayer);

	/**
	* ����һ��LibVlc ʵ��
	* ����һ������ 0-�����ɹ� -1-ʧ��
	*/
	CoreAPI int CreateVlcInstance();

	/**
	* ����һ�����������������һ����Ƶ���
	* /����hwnd ���������һ��win32/win64 API ���ɵľ��
	*/
	CoreAPI void SetDrawable(void *hwnd);

	/**
	* ����������Ƶ���
	* /���� path ��Ƶ����·��
	*/
	CoreAPI void CreateLocalMedia(const char *path);

	/**
	* ����������Ƶ���
	* /���� url ��Ƶ��Դ����
	*/
	CoreAPI void CreateRemoteMedia(const char *url);

	/**
	* ����һ�����������������һ����Ƶ���
	* \����hwnd ���������һ��win32/win64 API ���ɵľ��
	*/
	CoreAPI void Play();

	/**
	* ��ͣ��Ƶ   ʹ�÷�������ͨ�����ø÷���ֹͣ���ź��ٵ��һ�μ��ɴӵ�ǰλ�ÿ�ʼ����
	*/
	CoreAPI void Pause();

	/**
	* �ͷ�ʹ�õ���Դ
	* \����һ������ 0��ʾ�ɹ� -1 ��ʾʧ��
	*/
	CoreAPI int Destory();


	