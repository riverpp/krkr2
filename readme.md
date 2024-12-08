This is the Kirikiri2 source code.

Currently, the source code's portability is unfortunately not very high. We plan to
improve it gradually while listening to feedback from others.

If you're considering porting to other platforms, or if you'd like to help with
porting, please come to the IRC channel #kirikiriirc.

Due to licensing requirements, you must have C++ Builder 5 Professional, but we can
provide the build environment as is. Please contact us if you need it.


■ Source-related TODO ------------------------------------------------------------

  Quite urgent



   ・Want to fix this messy class structure and file structure somehow
   ・Want to get rid of Borland C++ Builder and VCL
   ・Want to make it compilable with gcc


      → But there's no time


■ Subversion Repository -----------------------------------------------------

  The Subversion repository is at the following location. No comments about commit
timing please.

  https://sv.kikyou.info/svn/kirikiri2/

  Username and password are required for commits. If you absolutely must commit,
please contact us.

■ STL Bug ----------------------------------------------------------------

There are versions of Rogue Wave's memory.stl that contain bugs.

Please apply this patch. Otherwise, memory leaks will occur when performing stable
sort with TJS2's Array.sort.

diff -Naur old/memory.stl new/memory.stl
--- old/memory.stl	2004-11-01 16:35:43.764744500 +0900
+++ new/memory.stl	2004-11-01 16:35:50.733672900 +0900
@@ -196,8 +196,8 @@
   template <class ForwardIterator> 
  _RWSTD_TRICKY_INLINE void __destroy (ForwardIterator first, ForwardIterator last)
  {
-    while (first != last)
-      ++first;
+     for ( ; first != last; ++first)
+        __destroy(&*first);
  }
#if defined(_RWSTD_NO_DESTROY_BUILTIN) || defined(_RWSTD_NO_DESTROY_NONBUILTIN)
//


■ About Licensing --------------------------------------------------------

  Please refer to the attached license.txt.


■ About the Source Code ------------------------------------------------------------

  I've said it's messy enough times but it's messy. Please forgive the occasional
syntax errors in comments.


■ Other Requirements --------------------------------------------------------------

  For Win32 version, Borland C++ Builder 5 is required. While there are still some
VCL dependencies, it could theoretically be written with SDK only, but the author
lacks time.

  For dependent libraries, please refer to the "Acknowledgments" in the documentation.


■ TJS2 ----------------------------------------------------------------------

  TJS2 doesn't depend on VCL, so it can be compiled with Borland Commandline Tools
(freely available). Don't know if it can be compiled with VC++.

  Confirmed to compile on Solaris/gcc 2.95.2. Header file modifications needed for
wstring-related items. Location uncertain.


■ Binaries ------------------------------------------------------------------

  Not included.


■ Basic Operation Flow ----------------------------------------------------------

  The Win32 version entry point is in kirikiri2/src/core/environ/win32/tvpwin32.cpp.

  It checks command line parameters and the initial script to execute.
  If no initial script is found, it links krdevui.dll and displays a dialog for
the user to select the initial script.

  After TVPSystemInit() completes basic initialization, it creates a control window
and enters the message loop.

  Then executes the initial script. After script execution, it follows the script's
flow. If no windows are created during initial script execution, the program
terminates.

  If the initial script still isn't found or if "Don't Select" is clicked in the
initial selection dialog, the control window is displayed, awaiting user input.

  ...Event handling is the most complex part; documentation needs to be improved.


■ Plugin Source ----------------------------------------------------------

  There are several sample programs for those who want to create Kirikiri plugins.


kirikiri2/src/plugins/win32 is the directory for plugin-related files (Win32).

・kirikiri2/src/plugins/win32/basetest
  Sample for adding usable functions to Kirikiri

・kirikiri2/src/plugins/win32/extrans
  Extended transition plugin source
                        (For those wanting to create transition plugins)

・kirikiri2/src/plugins/win32/fftgraph
  fftgraph (spectrum analyzer) plugin. Shows how to get PCM data from playback
  buffer and how to write images to layers.

Additionally, directories starting with 'wu' in kirikiri2/src/plugins/win32/ contain
plugins for extending PCM formats. These are for those wanting to write plugins to
add playable PCM formats to Kirikiri. These plugins are compatible with Kirikiri1.

Note that plugin specifications are not finalized, except for PCM format plugins.


■ Contact --------------------------------------------------------------------

 W.Dee <dee@kikyou.info>