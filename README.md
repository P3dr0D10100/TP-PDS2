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