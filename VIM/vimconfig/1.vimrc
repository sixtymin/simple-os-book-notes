
set nu
set hlsearch
set autoindent

set tabstop=4
set showmode
set ruler


syntax enable
syntax on

colorscheme desert


let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1


let g:winManagerWindowLayout='FileExplorer|TagList'
nmap wm :WMToggle<cr>

:set cscopequickfix=s-,c-,d-,i-,t-,e-