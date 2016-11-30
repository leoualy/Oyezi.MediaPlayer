/*****************************************************************************
*vlc_callback.h : 包含vlc事件回调的处理逻辑
*****************************************************************************
*     创建者:    liuyuan      QQ:991258519
* github地址:    leoualy/Oyezi.MediaPlayer
*   创建日期:    2016/11/30
*
*      描述:    1、视频缓冲事件的回调函数类型
                2、视频播放结束事件的回调函数类型
                3、media的事件监听器，实现与media相关事件的回调逻辑
		4、media_player的事件监听器，实现与media_player相关事件的回调逻辑
*****************************************************************************/

#ifndef VLC_H
#define VLC_H
#include <vlc\vlc.h>
#endif

// 视频缓冲事件的回调函数类型
typedef void (*BufferingCallback)(float newCache);
// 视频播放结束事件的回调函数类型
typedef void (*EndedCallback)();


