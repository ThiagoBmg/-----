# Trabalho prático – CC2632

## Membros 
- Thiago Braga Martins Gomes * Matrícula 22121064-4
- Matteo Kozakevic Nardi  * Matrícula 22.120.050-4

## ⭐️ Sobre
O trabalho prático da disciplina tem por objetivo desenvolver um algoritmo que simule um gerenciador
financeiro. Esse gerenciador financeiro deverá armazenar informações de receitas e gastos de uma carteira
pessoal. Além das funcionalidades descritas abaixo, o aluno deverá propor e implementar, pelo menos, mais 2
funcionalidades. O trabalho poderá ser feito de forma individual ou em duplas.

## ✨ Features
* Minha Carteira: local aonde o usuário pode monitorar em tempo real a situação de sua carteira e pensar em estratégias para melhorar seu cenário. 
* Dashboards: Possibilidade de extrair relatórios com dados da carteira do usuário

## 📦  Build
Para executar o projeto localmente, deve ser levado em consideração a instalação do [GCC](https://gcc.gnu.org/install/binaries.html) para compilação e geração do executavel.

Pensando em um cenário que podemos enfrentar, de incompatibilidade de sistema operacional, decidimos implementar o uso do Docker para garantir que o projeto funcione corretamente em um sistema Linux-Ubuntu.

## Criando com o Docker  
```bash
# criando imagem e iniciando container com o Docker
make build
```

```bash
# quando o container já estiver inciado, basta digitar make para iniciar o projeto
make
```

## Criando e iniciando o projeto localmente
```bash
# para iniciar o projeto localmente basta digitar make
make
```

## Iniciando o projeto através do Replit
https://replit.com/@ThiagoBmg/genfinfei

basta clicar no botão RUN, na perte superior da interface 

## Comandos 
```bash
# para iniciar o projeto localmente, atualizando a branch master antes
make  

# para iniciar os testes
make test 

# para construir o projeto com o Docker
make build 

# para iniciar o projeto sem buscar a versão mais atualizada
make start 

# para atualizar a branch master
make updateBranch 

# para remover o cenário do docker
make remove 
```
## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)