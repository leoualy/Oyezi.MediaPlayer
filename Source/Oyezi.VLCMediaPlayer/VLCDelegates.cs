using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Oyezi.VLCMediaPlayer
{
    /// <summary>
    /// 缓冲回调委托
    /// </summary>
    /// <param name="newCache"></param>
    public delegate void BufferingEventHandler(float newCache);
    public delegate void EndedEventHandler();
}
