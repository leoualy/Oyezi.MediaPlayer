using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Runtime.InteropServices;
using System.Windows.Interop;

namespace Oyezi.Sample.WPF
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        
        public MainWindow()
        {
            InitializeComponent();
            media.OnBuffered += media_OnBuffered;
        }

        void media_OnBuffered(float newCache)
        {
            //throw new NotImplementedException();
            this.Dispatcher.Invoke(() =>
            {
                this.Title = newCache.ToString();
            });
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string url = "http://download.blender.org/peach/bigbuckbunny_movies/big_buck_bunny_480p_surround-fix.avi";
            string path = @"J:\test.wmv";
            media.PlayLocal(path);
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            media.Pause();
        }
    }
}
