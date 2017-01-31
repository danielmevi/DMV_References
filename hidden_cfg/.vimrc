source $VIMRUNTIME/mswin.vim


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Vundle
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set nocompatible              " be iMproved, required
filetype off                  " required
"filetype on                  " temporary enalbe until plugins installed

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
"Plugin 'VundleVim/Vundle.vim'
Plugin 'Valloric/YouCompleteMe'
Plugin 'scrooloose/syntastic'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

let g:ycm_server_python_interpreter = "/usr/intel/bin/python2.7" 
let g:ycm_python_binary_path = 'python'
let g:ycm_confirm_extra_conf = 0

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" General
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
highlight Pmenu ctermbg=White
set history=100        " How many lines of history to remember
set ffs=unix,dos,mac   " support all three, in this order
filetype plugin indent on " load filetype plugins
set viminfo+=!         " make sure it can save viminfo
set isk+=_,$,@,%,#,-,. " none of these should be word dividers, so make them not be
set helplang=es        " spanish help
set completeopt=longest,menu " for omnipotent
behave mswin           " control mouse behavior

set diffexpr=

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" ycmCompleter Goto
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

nnoremap <leader>go  : YcmCompleter GoTo<CR>
nnoremap <leader>def : YcmCompleter GoToDefinition<CR>
nnoremap <leader>dec : YcmCompleter GoToDeclaration<CR>
nnoremap <leader>inc : YcmCompleter GoToInclude<CR>
nnoremap <leader>fix : YcmCompleter FixIt<CR>
nnoremap <leader>p   : YcmCompleter GetParent<CR>
nnoremap <leader>t   : YcmCompleter GetType<CR>



"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Fold
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

setlocal foldmethod=manual

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Moves
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" Moves to begin and end of line
nnoremap 8 ^
nnoremap 9 $
" Moves page up and page down
nnoremap - <C-B>
nnoremap = <C-F>
" Moves backward and forward in edited locations
nnoremap < :g;<CR>
nnoremap > :g,<CR>

" Map movements of C-E to other key combination

" Marks
" m<mark_name>    -> creates mark under cursor
" '<mark_name>    -> return to mark name 
" :'<mark1>, '<mark2> <command>
"       i.e: :'x, 'y d           -> delete lines from mark x to mark y
"       i.e: :45, 75 w foo.cpp   -> cut lines from 45 to 75 and write them to foo.cpp file

" Las edit line
" '.              -> jump to line where last edit was made

" Open header or source file
nnoremap <F11> :e %<.h<CR>
nnoremap <F12> :e %<.cc<CR>

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Clang
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Formating
map <C-E> :pyf ~/clang-format.py<cr>
imap <C-E> <ESC>:pyf ~/clang-format.py<cr>

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Syntatics
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" DEPRECATED
"execute pathogen#infect()
"set statusline+=%#warningmsg#
"set statusline+=%{SyntasticStatuslineFlag()}
"set statusline+=%*
"
"let g:syntastic_always_populate_loc_list = 1
"let g:syntastic_auto_loc_list = 2
"let g:syntastic_check_on_open = 1
"let g:syntastic_check_on_wq = 0
"let g:syntastic_enable_balloons = 1
"let g:syntastic_enable_highlighting = 1

"let g:syntastic_cpp_cpp_exec = "/usr/intel/pkgs/gcc/5.2.0/bin/g++"


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Spellcheck
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

:map <F7> :setlocal spell! spelllang=en_us<CR>

"Commands"
" Find next      -> ]s
" Find previous  -> [s
" Suggestions    -> z= 
" <F7>           -> enable/disable


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Files/Backups
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set autoread   " auto reload all files if they change outside the editor
set nobackup   " make backup file
set autowrite  " auto writefile when sth happened such as :make or :last or others.See the help
set makeef=error.err " When using make, where should it dump the file

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Theme/Colors
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
syntax on " syntax highlighting on
set background=light
set background=dark

"if has("gui_running")
    "set guifont=Ubuntu\ Mono\ 13
    "set printfont=Ubuntu\ Mono\ 13
    "set guifont=Droid\ Sans\ Mono\ 10
    "set printfont=Droid\ Sans\ Mono\ 10
    "set guifont=Droid\ Sans\ Mono\ 13
    "set printfont=Droid\ Sans\ Mono\ 11
    "set guifont=Droid_Sans_Mono:h9:cANSI
    "set printfont=Droid_Sans_Mono:h9:cANSI
    "set guifont=Inconsolata:h11:cANSI
    "set printfont=Inconsolata:h11:cANSI
    "set guifont=Consolas:h10
    "set printfont=Consolas:h9
    "set linespace=0   " vertical space between text lines.
    "colorscheme ir_black
"else
"   colorscheme ir_black 
"endif

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Vim UI
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set wildmenu       " turn on wild menu
set ruler          " Always show current positions along the bottom
set cmdheight=2    " the command bar is 1 high
"set list           " show whitespace at the end of lines.
set number         " turn on line numbers
set numberwidth=4  " minimum width to use for the number column,not a fix size
set hid            " you can change buffer without saving
set backspace=2    " make backspace work normal
set whichwrap+=<,>,h,l  " backspace and cursor keys wrap to
set mouse=a        " use mouse everywhere
set shortmess=atI  " shortens messages to avoid 'press a key' prompt
set report=0       " tell us when anything is changed via :...
set lz             " do not redraw while running macros (much faster) (LazyRedraw)
                   " make the splitters between windows be blank
set fillchars=vert:\ ,stl:\ ,stlnc:\
set textwidth=119
set mousehide
set hidden
set showcmd
set ignorecase
set smartcase      " overrides ignorecase if uppercase used in search string (cool)
set cursorline
"set cursorcolumn

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Visual Cues
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set showmatch      " show matching brackets
set hlsearch       " do highlight searched for phrases
set incsearch      " BUT do highlight as you type you search phrase
set scrolloff=4    " Keep 4 lines (top/bottom) for scope
"set novisualbell   " don't blink
set noerrorbells   " no noises for error
"set vb t_vb=       " no noises for other
set laststatus=2   " always show the status line
"set statusline=\(%02.n\)\ %<%f\ %h%m%r%=%y\ %-14.(%l,%c%V%)\ %P
set statusline=\(%02.n\)\ %<%f\ %h%m%r%=%-14.(%l,%c%V%)\ %P

"set listchars=tab:\|\ ,trail:.,extends:>,precedes:<,eol:$ " what to show when I hit :set list

" substitute <tab>, <space>, and other indentation guide characters. [… · • »]
" For windows
"set list listchars=tab:»·,trail:•,extends:…,precedes:…,eol:¶
" For Linux
set listchars=tab:\|\ ,trail:.,extends:>,precedes:<,eol:$ " what to show when I hit :set list


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Text Formatting/Layout
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set formatoptions+=mM " for charactors fold and patch
set autoindent    " autoindent
set smartindent   " smartindent
set cindent       " do c-style indenting
set tabstop=4     " tab spacing (settings below are just to unify it)
set softtabstop=4 " unify
set shiftwidth=4  " unify
set expandtab     " no real tabs please!
set nowrap        " wrap lines
set smarttab      " use tabs at the start of a line, spaces elsewhere
"set dictionary=/usr/share/dict/american-english "use dictionary when input the english word
set selection=exclusive "Select up to (including) the character where cursor is (use exclusive to avoid including it).

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Folding
" Enable folding, but by default make it act like folding is off, because folding is annoying in anything but a few rare cases
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set foldenable       " Turn on folding
set foldlevel=100    " Don't autofold anything (but I can still fold manually)
set foldopen-=search " don't open folds when you search into them
set foldopen-=undo   " don't open folds when you undo stuff

" Cycle through all buffers.
nnoremap <silent> 1 :bprevious<CR>:redraw<CR>:ls<CR>
nnoremap <silent> 2 :bnext<CR>:redraw<CR>:ls<CR>
"nnoremap <silent> <C-Tab> :tabprevious<CR>:redraw<CR>
"nnoremap <silent> <C-S-Tab> :tabNext<CR>:redraw<CR>
"nnoremap <silent> <A-1> :buffer 1<CR>
"nnoremap <silent> <A-2> :buffer 2<CR>
"nnoremap <silent> <A-3> :buffer 3<CR>
"nnoremap <silent> <A-4> :buffer 4<CR>
"nnoremap <silent> <A-5> :buffer 5<CR>
"nnoremap <silent> <A-6> :buffer 6<CR>
"nnoremap <silent> <A-7> :buffer 7<CR>
"nnoremap <silent> <A-8> :buffer 8<CR>
"nnoremap <silent> <A-9> :buffer 9<CR>
"nnoremap <silent> <A-0> :buffer 10<CR>

" Buffer switch commands
" :b #number



" make the arrow keys move within wrapped lines
"map <Up> gk
"imap <Up> <C-o>gk
"map <Down> gj
"imap <Down> <C-o>gj

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Toggle Menu and Toolbar
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"if has("gui_running")
"   set guioptions+=b
"   set guioptions-=m
"   set guioptions-=T
"   map <silent> <F11> :if &guioptions =~# 'T' <Bar>
"            \set guioptions-=T <Bar>
"            \set guioptions-=m <bar>
"        \else <Bar>
"            \set guioptions+=T <Bar>
"            \set guioptions+=m <Bar>
"        \endif<CR>
"
"   nnoremap <silent> <F9> :highlight Comment guifg=#2A2A2A guibg=NONE gui=NONE ctermfg=darkgray ctermbg=NONE cterm=NONE<CR>
"   nnoremap <silent> <S-F9> :highlight Comment guifg=#7C7C7C guibg=NONE gui=NONE ctermfg=darkgray ctermbg=NONE cterm=NONE<CR>
"
"   "--------------------
"   " Function: Open tag under cursor in new tab
"   " Source:   http://stackoverflow.com/questions/563616/vimctags-tips-and-tricks
"   "--------------------
"   map <C-\> :tab split<CR>:exec("tag ".expand("<cword>"))<CR>
"
"   " Search for selected text, forwards or backwards.
"   vnoremap <silent> * :<C-U>
"     \let old_reg=getreg('"')<Bar>let old_regtype=getregtype('"')<CR>
"     \gvy/<C-R><C-R>=substitute(
"     \escape(@", '/\.*$^~['), '\_s\+', '\\_s\\+', 'g')<CR><CR>
"     \gV:call setreg('"', old_reg, old_regtype)<CR>
"   vnoremap <silent> # :<C-U>
"     \let old_reg=getreg('"')<Bar>let old_regtype=getregtype('"')<CR>
"     \gvy?<C-R><C-R>=substitute(
"     \escape(@", '?\.*$^~['), '\_s\+', '\\_s\\+', 'g')<CR><CR>
"     \gV:call setreg('"', old_reg, old_regtype)<CR>
"
"   nnoremap <silent> <F8> :NERDTreeToggle<CR>
"   nnoremap <silent> <F8> <ESC> :NERDTreeToggle<CR>
"
"endif

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Find file script and mappings
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

function! GrepQuick(pat)
  let all = getqflist()
  for d in all
    if bufname(d['bufnr']) !~ a:pat && d['text'] !~ a:pat
        call remove(all, index(all,d))
    endif
  endfor
  call setqflist(all)
endfunction
command! -nargs=* SearchQL call GrepQuick(<q-args>)

function! GrepQuickFix(pat)
  let all = getqflist()
  for d in all
    if bufname(d['bufnr']) !~ a:pat && !(d['text'] !~ a:pat)
        call remove(all, index(all,d))
    endif
  endfor
  call setqflist(all)
endfunction
command! -nargs=* GrepQF call GrepQuickFix(<q-args>)

" Search using quickfix to list occurrences: Easily GREP current word in current file.
" http://vim.wikia.com/wiki/Search_using_quickfix_to_list_occurrences
command GREP :execute 'vimgrep '.expand('<cword>').' '.expand('%') | :copen | :cc
command VGREP :vsplit | :execute 'vimgrep '.expand('<cword>').' '.expand('%') | :copen | :cc | :q
" TODO: Improve grepf to catch all CPP class methods
command GREPF :execute 'vimgrep ".*\S*::\S*.*"  % '  | :copen | :call GrepQuickFix(";") | :call GrepQuickFix("}") | :call GrepQuickFix("=") | :call GrepQuickFix(".") | :call GrepQuickFix(" \\* ") | :cc
command VGREPF :split | :execute 'vimgrep ".*\S*::\S*.*"  % '  | :copen | :call GrepQuickFix(";") | :call GrepQuickFix("}") | :call GrepQuickFix("=") | :call GrepQuickFix(".") | :call GrepQuickFix(" \\* ") | :cc | :q
command GREPDIR :execute 'vimgrep '.expand('<cword>').' *.*' | :copen | :cc
command VGREPDIR :vsplit | :execute 'vimgrep '.expand('<cword>').' *.*' | :copen | :cc | :q
nnoremap <silent> /<F2> :GREP<CR>
nnoremap <silent> <F2> :VGREP<CR>
nnoremap <silent> /<F3> :GREPDIR<CR>
nnoremap <silent> <F3> :VGREPDIR<CR>
nnoremap <silent> <F4> :GREPF<CR>
nnoremap <silent> /<F4> :VGREPF<CR>
nnoremap <silent> <F5> :cclose<CR>
command! -nargs=1 Grep :vsplit | :vimgrep <args> * | :copen | :cc | :q  
command! -nargs=1 HGreep :vimgrep <args> * | :copen | :cc  

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" gmake vim command
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" TODO: Add path parser and gmake command from vim for make idi_xtor, make vcs, make zse, make tbx and for 
" personal projects make

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" File Explorer
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let g:explVertical=1 " should I split verticially
let g:explWinSize=35 " width of 35 pixels

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Win Manager
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let g:winManagerWidth=35 " How wide should it be( pixels)
let g:winManagerWindowLayout = 'FileExplorer,TagsExplorer|BufExplorer' " What windows should it

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" CTags and Taglist
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" For Windows
"let Tlist_Ctags_Cmd = "C:\\Progra~1\\Vim\\Vim72\\ctags.exe" " Location of my ctags
" For Linux
let Tlist_Ctags_Cmd = "ctags"       " Location of my ctags

let Tlist_Sort_Type = "name"        " order by
let Tlist_Use_Right_Window = 0      " split to the left side of the screen
let Tlist_Compact_Format =  0       " show small menu
let Tlist_Exit_OnlyWindow = 1       " if you are the last, kill yourself
let Tlist_File_Fold_Auto_Close = 0  " Do not close tags for other files
let Tlist_Enable_Fold_Column = 0    " Show folding tree
let Tlist_Show_One_File = 1         " only display the tag of current file

set tags=./tags,../tags,./../../tags,./**/tags  " which tags files CTRL-] will search
set autochdir " auto change the current dierctory when you open the file or window or any other buffer
set makeef=makeerror.err
set path=.,./../**

nmap <S-F10> :!ctags -R .<CR>
nmap <F10> :TlistToggle<CR>
nmap <F10><ESC> :TlistToggle<CR>



"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Cscope
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
if has("cscope")
        set csprg=cscope
        set csto=0
        set nocst
        set nocsverb
        " add any database in current directory
        if filereadable("cscope.out")
            cs add cscope.out
        elseif $CSCOPE_DB != ""
            cs add $CSCOPE_DB
        endif

        " show msg when any other cscope db added
        set cscopeverbose
        set csverb
        set cscopetag
        set cscopequickfix=s-,g-,c-,d-,t-,e-,f-,i-

        " Using 'CTRL-spacebar' then a search type makes the vim window
        " split horizontally, with search result displayed in
        " the new window.

        nmap <C-Space>s :scs find s <C-R>=expand("<cword>")<CR><CR>
        nmap <C-Space>g :scs find g <C-R>=expand("<cword>")<CR><CR>
        nmap <C-Space>c :scs find c <C-R>=expand("<cword>")<CR><CR>
        nmap <C-Space>t :scs find t <C-R>=expand("<cword>")<CR><CR>
        nmap <C-Space>e :scs find e <C-R>=expand("<cword>")<CR><CR>
        nmap <C-Space>f :scs find f <C-R>=expand("<cfile>")<CR><CR>
        nmap <C-Space>i :scs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
        nmap <C-Space>d :scs find d <C-R>=expand("<cword>")<CR><CR>

        " Hitting CTRL-space *twice* before the search type does a vertical
        " split instead of a horizontal one

        nmap <C-Space><C-Space>s
                \:vert scs find s <C-R>=expand("<cword>")<CR><CR>
        nmap <C-Space><C-Space>g
                \:vert scs find g <C-R>=expand("<cword>")<CR><CR>
        nmap <C-Space><C-Space>c
                \:vert scs find c <C-R>=expand("<cword>")<CR><CR>
        nmap <C-Space><C-Space>t
                \:vert scs find t <C-R>=expand("<cword>")<CR><CR>
        nmap <C-Space><C-Space>e
                \:vert scs find e <C-R>=expand("<cword>")<CR><CR>
        nmap <C-Space><C-Space>i
                \:vert scs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
        nmap <C-Space><C-Space>d
                \:vert scs find d <C-R>=expand("<cword>")<CR><CR>
endif

autocmd FileType python set omnifunc=pythoncomplete#Complete
autocmd FileType javascript set omnifunc=javascriptcomplete#CompleteJS
autocmd FileType html set omnifunc=htmlcomplete#CompleteTags
autocmd FileType css set omnifunc=csscomplete#CompleteCSS
autocmd FileType xml set omnifunc=xmlcomplete#CompleteTags
autocmd FileType php set omnifunc=phpcomplete#CompletePHP
autocmd FileType c set omnifunc=ccomplete#Complete

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Code snippets
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
if has("code-snippet")
   StringAbbrGlobal summary    "/// <summary>\n/// [~summary~]\n/// <\/summary>"
   StringAbbrGlobal param      "/// <param name='[~name~]'>[~desc~]</parameter>\n"
   StringAbbrGlobal port       "/// <port name='[~name~]'>[~desc~]</port>\n"
   StringAbbrGlobal remarks    "/// <remarks>\n// [~remarks~]\n// </remarks>"
"   StringAbbrGlobal //---     "//--------------------------------------------------------------------------\n"
   StringAbbrGlobal bend       "begin\n[~body~]\nend"
"   StringAbbrGlobal function  "function automatic [~returntype~] [~name~] ( [~paramtype~] [~paramname~] )\n   returns [~returnvalue~];\nendfunction"
"   StringAbbrGlobal task      "task automatic [~name~] ( [~paramtype~] [~paramname~] )\n   [~body~]\nendtask"
   StringAbbrGlobal acomb      "/// <summary>\n/// [~summary~]\n/// <\/summary>\nalways_comb begin : [~name~]\nend"
endif


