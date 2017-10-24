
set number      " 显示行号

set hlsearch    " 搜索逐字符高亮
set incsearch   " 开启实时搜索功能
set ignorecase   " 搜索时大小写不敏感
set nocompatible " 关闭兼容模式

set wildmenu    " vim 自身命令行模式智能补全

set autoindent  " 自动缩进
set tabstop=4   " 缩进大小为4个空格

set softtabstop=4 " 统一缩进为4
set shiftwidth=4
set expandtab     " 使用空格代替制表符

set showmode

syntax enable   " 开启语法高亮
syntax on

colorscheme desert " 选择背景主题

set cul            " 高亮光标所在行
autocmd InsertEnter * se cul    " 用浅色高亮当前行  
set ruler           " 显示标尺 

" 状态行显示的内容  
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}   


set foldmethod=syntax   " 基于缩进或语法进行代码折叠
set nofoldenable  " 启动 vim 时关闭折叠代码

" TagList
let Tlist_Use_Right_Window = 1  " 在右侧显示窗口  
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1


let g:winManagerWindowLayout='FileExplorer|TagList'
nmap wm :WMToggle<cr>

:set cscopequickfix=s-,c-,d-,i-,t-,e-

