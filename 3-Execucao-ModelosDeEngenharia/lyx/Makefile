#========================================================#
# Makefile para gerar versões da tese                    #
#========================================================#
# Comando               Gera o arquivo
# make dvi: 		Monografia-Dissertacao-Tese-master.dvi
# make ps: 		Monografia-Dissertacao-Tese-master.ps
# make pdf: 		Monografia-Dissertacao-Tese-master.pdf
# make ps-2on1: 	Monografia-Dissertacao-Tese-master-2on1.ps
# make pdf-2on1: 	Monografia-Dissertacao-Tese-master-2on1.pdf

# Diretorio onde os arquivos temporarios serão armazenados
OUTPUT=/tmp/

all: dvi pdflatex
x2:  dvi ps 2on1.ps
x:   dvi ps tex2pdf
lyx: pdf 2on1.ps
pdflatex: pdflatex

#========================================================Gera o dvi a partir do latex
latex: dvi
dvi:  3-Projeto-ModelosDeEngenharia-Master.tex
	echo "No LyX você deve exportar o arquivo com a opção: file->export->Latex(simples)."
	echo "make dvi: gera arquivo da tese no formato dvi."
	echo "Running latex......(1)\a"
	latex 3-Projeto-ModelosDeEngenharia-Master.tex
	echo "Running BIBTEX.....(1b)\a"
	bibtex 3-Projeto-ModelosDeEngenharia-Master
	echo "ReRunning latex....(2)\a"
	latex 3-Projeto-ModelosDeEngenharia-Master.tex
# Retire o comentário das duas linhas abaixo se usar indice remissivo no final da tese
# echo "Running makeindex....(2b)\a"
# makeindex 3-Projeto-ModelosDeEngenharia-Master.idx
	echo "ReRunning latex....(3)\a"
	latex 3-Projeto-ModelosDeEngenharia-Master.tex
	echo "Rerunning latex....(4)\a"
	latex 3-Projeto-ModelosDeEngenharia-Master.tex
	echo "Rerunning latex....(5)\a"
	latex 3-Projeto-ModelosDeEngenharia-Master.tex
	echo "Versão da tese no formato dvi pronta."
	ls -lah 3-Projeto-ModelosDeEngenharia-Master.dvi

#========================================================Visualização do dvi
xdvi: 3-Projeto-ModelosDeEngenharia-Master.dvi
	echo "make xdvi: executa o visualizador do arquivo da tese no formato dvi."
	xdvi 3-Projeto-ModelosDeEngenharia-Master.dvi

#========================================================Gera ps a partir de dvi
dvips: 3-Projeto-ModelosDeEngenharia-Master.dvi
	echo "make ps: gera arquivo da tese no formato ps (Dimensoes A4)."
	dvips -D 600 -t portrait -T 21.0cm,29.7cm -o "3-Projeto-ModelosDeEngenharia-Master.ps" 3-Projeto-ModelosDeEngenharia-Master.dvi
## dvips -o 3-Projeto-ModelosDeEngenharia-Master.ps 3-Projeto-ModelosDeEngenharia-Master.dvi

#========================================================Gera pdf a partir de ps
ps2pdf: 3-Projeto-ModelosDeEngenharia-Master.ps
	echo "make ps2pdf: converte arquivo ps para pdf (gera arquivo da tese no formato pdf)."
	echo "ps2pdf -sPAPERSIZE=a4 ..."
	ps2pdf -sPAPERSIZE=a4 3-Projeto-ModelosDeEngenharia-Master.ps
#========================================================Gera 2on1.ps (formato brochura para costura)
2on1.ps: 3-Projeto-ModelosDeEngenharia-Master.ps
	echo "make 2on1.ps:  gera arquivo da tese no formato ps com 2 páginas em uma."
	echo "Executando psbook e pstops..."
	psbook -s20 3-Projeto-ModelosDeEngenharia-Master.ps | pstops -pa4 "4:0@.7L(21cm,00)+1L@.7(21cm,14.8cm),2L@.7(21cm,00)+3L@.7(21cm,14.8cm)" > 3-Projeto-ModelosDeEngenharia-Master-2on1.ps

#========================================================Gera 2on1.pdf (duas páginas em uma)
2p: 	3-Projeto-ModelosDeEngenharia-Master.ps
	echo "make 2p: Converte arquivo A4.ps em arquivo com 2 páginas em cada folha A4"
	cat 3-Projeto-ModelosDeEngenharia-Master.ps | pstops -pa4 "4:0@.7L(21cm,00)+1L@.7(21cm,14.8cm),2L@.7(21cm,00)+3L@.7(21cm,14.8cm)" > 3-Projeto-ModelosDeEngenharia-Master-2p.ps

#========================================================Gera 2on1.pdf
2on1.pdf: 3-Projeto-ModelosDeEngenharia-Master-2p.ps
	echo "make 2on1.pdf: gera arquivo da tese no formato pdf com 2 páginas em uma."
	ps2pdf 3-Projeto-ModelosDeEngenharia-Master-2p.ps

#========================================================Gera ps a partir de pdf
pdf2ps: 3-Projeto-ModelosDeEngenharia-Master.pdf
	echo "make pdf2ps: gera arquivo da tese no formato ps a partir da versão pdf."
	echo "pdf2ps..."
	pdf2ps -dLanguageLevel=1 3-Projeto-ModelosDeEngenharia-Master.pdf 3-Projeto-ModelosDeEngenharia-Master.ps
#	echo "mpage..."

#========================================================Gera pdf usando pdflatex
pdflatex: 3-Projeto-ModelosDeEngenharia-Master.tex
	echo "make pdflatex: gera arquivo da tese no formato pdf partindo diretamente do arquivo tex."
	echo "No LyX você deve exportar o arquivo com a opção: file->export->Latex(pdflatex)."
	echo "Running pdflatex...(1)\a"
	pdflatex 3-Projeto-ModelosDeEngenharia-Master.tex
#thumbpdf 3-Projeto-ModelosDeEngenharia-Master.tex
	echo "Running BIBTEX.....(1b)\a"
	bibtex 3-Projeto-ModelosDeEngenharia-Master
	echo "ReRunning pdflatex...(2)\a"
	pdflatex 3-Projeto-ModelosDeEngenharia-Master.tex
#thumbpdf 3-Projeto-ModelosDeEngenharia-Master.tex
	echo "Rerunning pdflatex....(3)\a"
	pdflatex 3-Projeto-ModelosDeEngenharia-Master.tex
#thumbpdf 3-Projeto-ModelosDeEngenharia-Master.tex
	echo "Rerunning pdflatex....(4)\a"
	pdflatex 3-Projeto-ModelosDeEngenharia-Master.tex
	acroread 3-Projeto-ModelosDeEngenharia-Master.pdf &

#========================================================Gera pdf usando tex2pdf direto
tex2pdf :
	echo "make tex2pdf: gera arquivo da tese no formato pdf partindo diretamente do arquivo tex."
	tex2pdf 3-Projeto-ModelosDeEngenharia-Master.tex

#========================================================Eliminando arquivos temporários
clean:
	echo "make clean: Eliminar os arquivos temporários."
	rm -f *.ps *.dvi *.aux *.toc *.idx *.ind *.ilg *.log *.out *.lyx~ *.blg *.lof *.lot *.bbl *.brf *.nlo *~


#========================================================PROGRAMAS UTILIZADOS

# mpage: gera duas páginas em uma com borda (as vezes não funciona)
# psbook -s4 (cria livro rearranjando cada 4 páginas em 1)
# psbook -s40 (cria livro rearranjando cada 40 páginas em 10)
# pstops ?
# psnup coloca em  1 página A4 duas páginas
