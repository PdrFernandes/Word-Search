BUSCADOR DE PALAVRAS

== Informações gerais ==

Primeiro trabalho realizado na graduação para o aprendizado de estrutura de dados

== Informacoes do arquivo ==

Nome do programa: "ep"
Nomes dos tipos de indices: "lista" ou "arvore"
Arquivos para teste: "bb.txt", "longo.txt", "longor.txt" e "texto.txt"


== Modo de compilacao no prompt de comandos do Windows ==

1. Aperte as teclas WIN + R, digite "cmd" e pressione a tecla ENTER;
2. Acesse a pasta em que os arquivos estão localizados com o comando: cd <caminho-do-arquivo>;
3. Para compilar, na pasta local dos arquivos, execute o comando: gcc ep.c -o ep1.exe
4. Um arquivo executavel chamado ep1 será criado na pasta, rode o programa especificando, na ordem, o nome do programa, o nome do arquivo de texto e o nome do tipo de indice.

Ex: C:\Users\jose\aed-ep>gcc ep.c -o ep1.exe

    C:\Users\pedro\Desktop\Projeto AED1\v5>ep1 texto.txt lista

== Modo de compilacao no prompt de comandos do Linux ==

1. Abra o terminal;
2. Acesse o diretório, em que o arquivo esta localizado com o comando: cd <caminho-do-arquivo>;
3. Para compilar, na pasta local do arquivo, execute o comando: gcc ep.c -o ep1
4. Um arquivo chamado ep1 será criado na pasta e para rodar o programa digite no terminal na ordem, o nome do programa, o nome do arquivo de texto e o nome do tipo de indice,
   através do comando: ./ep1 <nome do arquivo de texto .txt> <tipo de indice>


Ex: pedro@pedro-PC:~/Documentos/ep$ gcc ep.c -o ep1
    pedro@pedro-PC:~/Documentos/ep$ ./ep1 texto.txt lista

