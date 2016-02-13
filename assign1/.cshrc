setenv OSTYPE `/bin/uname -s`
if ( $OSTYPE == "Linux" ) then
setenv PATH ~/bin:/usr/local/turnin:${USRLOCAL}:${JDK}:${SYSTEM}:{FACEBIN}:/home/maynard/bin:.
if ($?USER == 0 || $?prompt == 0) exit
set history=100
set ignoreeof
set prompt="`hostname` `whoami`\!: "
alias cs2123 "cd ~/courses/cs/2123"
set cdpath=( ~/courses/cs ~ )
setenv SUB_cs2123 "section1"
alias locate "locate -d /var/lib/mlocate/mlocate.db:/usr/local/mlocate/mlocate.db"
