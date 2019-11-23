# Trabalho Prático: Máquina de Busca
Este reposítorio contém os arquivos referentes ao trabalho prático da disicplina de Programação e Desenvolvomento
de Software II (PDS-II) dos alunos Pedro Dias e Leonel Mota. 

O trabalho foi completamente desenvolvido e testado na plataforma *Windows (Windows 10)*. Sendo assim, recomenda-se que,
se posível, o trabalho seja compilado e testado nessa plataforma. 

## Instruções de compilação:
- Utilizando o git, clone este repositório na máquina local.
- Abra a linha de comandos no diretório em que o respositório foi clonado.
- Utilize o comando ```make all``` para compliar todos os binários do projeto (referentes aos testes de unidade e ao programa principal).
- Caso deseje compilar componentes individuais, utilize um dos comandos abaixo:
    * ```make main``` para compilar apenas o programa principal.
    * ```make Teste``` para compilar apenas os testes de unidade, de ambas as classes (Documento e MBus).
    * ```make Teste_doc``` para compilar apenas os testes de unidade da classe Documento.
    * ```make Teste_busca``` para compilar apenas os testes de unidade da classe Busca.
- Após a compliação, os arquivos executáveis (.exe) estarão no diretório /bin.

O comando ```make clean``` também pode ser utilizado para limpar o diretório /bin (apagar todos os arquivos .exe e .o).

## Instruções de execução:
- Localize o executável do programa no diretório bin (main.exe).
- Clique duas vezes sobre o arquivo.
- Agora, será solicitado que você informe um diretório para inicializar a sua base de dados. Neste momento, 
você deve digitar o caminho para um diretório que contém ao menos um arquivo de texto.
**Atenção** este diretório deve conter apenas arquivos de texto. Todos os arquivos do diretório serão adicionados na
base de dados. 
Se quiser, você pode pular esse passo, digitando um ".", e adicionar os arquivos depois, manualmente, 
utilizando a opção *"Atualizar banco de dados"* e, depois, a opção *"Adicionar um documento".
- Depois disso, será apresentado um menu com as seguintes opções:
    * Realizar pesquisa. (onde você pode pesquisar por um conjunto de termos na base de dados)
    * Alterar banco de dados. (onde você pode adicionar e remover documentos da base de dados e também atualizá-la).
    * Sair
- A partir de então basta escolher a opção desejada em cada um dos menus do programa.
