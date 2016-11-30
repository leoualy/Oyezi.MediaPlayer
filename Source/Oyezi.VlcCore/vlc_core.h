/*****************************************************************************
*VlcCore.h : 定义必要的函数指针类型 ，公共变量，函数名
*****************************************************************************
*          创建者:     liuyuan      QQ:991258519
* github地址:     leoualy/Oyezi.MediaPlayer
*      创建日期:     2016/11/27
*
*              描述:     该DLL封装了VLC的底层库，C/C++可以直接调用，C#通过互操作也可以使用
*                             目前版本只是为了快速实现项目需要的功能：主要用来通过http加载网络视频
*                             除基本的播放暂停外，定义了缓冲事件的回调函数指针类型，.net 平台可以通过
*                             定义等价的委托和事件来将.net 的处理函数来进行注册
*                             目前程序结构比较简陋，但已满足需求。接下来将尽快丰富功能，调整结构，稳定性
*          修正1：
                                日期：2016/11/30
		                        内容：每次Play()函数会使视频从开始播放
		                        添加了视频结束事件，可以从外部注册视频结束的回调处理方法
*
*
*****************************************************************************/

#include<Windows.h>
#include"vlc_event.h"
#ifndef VLC_H
#define VLC_H
#include <vlc\vlc.h>
#endif

#ifndef CoreAPI
#define CoreAPI extern "C"  __declspec(dllexport)
#endif

libvlc_instance_t *pVLCInstance;                                     // libvlc 实例指针
libvlc_media_player_t *pVLCMediaPlayer;                  // mediaPlayer 实例指针
libvlc_media_t *pVLCMedia;

	/**
	* 创建一个LibVlc 实例
	* 返回一个整数 0-创建成功 -1-失败
	*/
	CoreAPI int CreateVlcInstance();

	/**
	* 设置一个句柄用来用来承载一个视频输出
	* /参数hwnd 这个参数是一个win32/win64 API 生成的句柄
	*/
	CoreAPI void SetDrawable(void *hwnd);

	/**
	* 创建本地视频输出
	* /参数 path 视频本地路径
	*/
	CoreAPI void CreateLocalMedia(const char *path);

	/**
	* 创建网络视频输出
	* /参数 url 视频资源链接
	*/
	CoreAPI void CreateRemoteMedia(const char *url);

	/**
	* 设置一个句柄用来用来承载一个视频输出
	* \参数hwnd 这个参数是一个win32/win64 API 生成的句柄
	*/
	CoreAPI void Play();

	/**
	* 暂停视频   使用方法：在通过调用该方法停止播放后，再点击一次即可从当前位置开始播放
	*/
	CoreAPI void Pause();

	/**
	* 释放使用的资源
	* \返回一个整数 0表示成功 -1 表示失败
	*/
	CoreAPI int Destory();

	CoreAPI void AttachBufferingCallback(BufferingCallback pBuffingCallback);
	CoreAPI void AttachEndedCallback(EndedCallback pEndedCallback);