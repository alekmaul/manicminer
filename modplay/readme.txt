MODPlay v0.66
=============

Five years after starting this project, which gained a little attention in the GP32 scene as many amateur game developers 
used it in their productions, I stumbled over these sources. As far as I recall, back then, I only released MODPlay with 
Protracker support, but the last thing I did was basically rewriting the whole thing and adding S3M and XM support. 
But unfortunately, the whole thing remained unreleased.

Today I feel like releasing this version to the public after cleaning up the sources quite a bit. I sincerely hope it will
 help developing all kinds of interesting and entertaining new productions, and maybe aid people improving their programming
  skills. Despite the existence of many other MOD playing libraries, I guess it might still be useful to some programmers 
  because of its ease of use, easily retargetable code and low requirements on CPU and memory. You may use it in your non-commercial 
  projects, as long as you give credits to me in your production. For commercial projects, you may request a permission from me.

The main library can be found in the "modplay" subdirectory. To compile it for any platform, simply compile each source file 
individually and add it to a library. The existing Makefile does that under Windows using the MingW compiler system. In the 
base directory you can find a file called "player.c" which demonstrates the usage of the library with SDL (which is assumed 
to be installed). It should be rather self-explanatory.

If you have any issues using, compiling or porting the library, feel free to contact me, even though it may take some time 
for me to reply as I might be busy.

Have fun and good luck with your projects!

    Christian Nowak a.k.a. chn, Esbjerg/Denmark, 20th October, 2007
    chnowak@web.de


PS: I would like to thank my girlfriend, now fiancé, Song Yangzemiao, for her moral support and for being by my side faithfully. 
wo shen shen de ai zhe ni!
