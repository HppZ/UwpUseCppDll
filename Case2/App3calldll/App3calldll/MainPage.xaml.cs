using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace App3calldll
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
            var r = new OSVersionInfo2();
            r.OSVersionInfoSize = Marshal.SizeOf(r);
            MyClass.GetVersionEx(ref r);
        }
    }


    class MyClass
    {
        [DllImport("api-ms-win-core-sysinfo-l1-1-0.dll",EntryPoint = "GetVersionEx")]
        public static extern bool GetVersionEx(ref OSVersionInfo2 osvi);


    }

    [StructLayout(LayoutKind.Sequential)]
    public struct OSVersionInfo2
    {
        public int OSVersionInfoSize;
        public int MajorVersion;
        public int MinorVersion;
        public int BuildNumber;
        public int PlatformId;

        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 128)]
        public String CSDVersion;
    }
}
