# **SIG-Circus: Um Sistema de Gestão para um Circo**

##  Desenvolvedores

* **Lucas da Costa Santos**  
  📧 [lucascsparelhas@gmail.com](mailto:lucascsparelhas@gmail.com)  
  🔗 [GitHub](https://github.com/lucascsantos07)

* **Vinícius Linhares Queiroz**  
  📧 [vinicius.linhares.702@ufrn.edu.br](mailto:vinicius.linhares.702@ufrn.edu.br)  
  🔗 [GitHub](https://github.com/ViniciusL07) 

* **Ícaro Nonato de Freitas**  
  📧 [icaro.freitas.113@ufrn.edu.br](mailto:icaro.freitas.113@ufrn.edu.br)  
  🔗 [GitHub](https://github.com/Icaro-Nonato) 

* **José Samuel Silva Lima**
  📧 [jose.lima.146@ufrn.edu.br](mailto:jose.lima.146@ufrn.edu.br)  
  🔗 [GitHub](https://github.com/Jose-Samuel-Lima)

---

## **Descrição do Projeto**
Este projeto foi desenvolvido para facilitar a gestão completa de um circo. O SIG-Circus integra em um único sistema o controle das principais áreas administrativas, tornando os processos mais ágeis e organizados.

Ele permite gerenciar clientes, com cadastro e consulta de informações; funcionários, organizando cargos e funções; vendas de ingressos, registrando entradas e receitas; relatórios, que auxiliam na análise e na tomada de decisões; e agendamentos, garantindo a programação eficiente dos espetáculos e eventos.

## **Ferramentas Utilizadas**
Linguagem: C

IDE: Visual Studio Code (VSCode)

Make/Makefile

Compilador: GCC (GNU Compiler Collection)

## **Como Rodar**
### **No Linux:**
Instale a extensão Makefile Tools no VSCode

Abra o terminal e navegue até a pasta do projeto.

```
cd ~/projeto/programa
```

Compile e execute o projeto:
```
make run
```

### **No Windows:**
1. Instalar o MSYS2: https://www.msys2.org
2. Atualizar pacotes do MSYS2

Depois de instalar, abra o MSYS2 MSYS (atalho criado na instalação) e digite:
```
pacman -Syu
```

3. Instalar GCC e Make

No terminal MSYS2 MinGW 64-bit (procure pelo atalho MSYS2 MinGW 64-bit), digite:

```
pacman -S mingw-w64-x86_64-gcc make
```

4. Verificar instalação

Depois da instalação, rode:
```
gcc --version
make --version
```

5. Verifique se o GCC está no PATH:
```
echo $PATH
```

6. Se necessário, adicione o GCC ao PATH:
```
export PATH=$PATH:/mingw64/bin
```

7. Compilação e execução
Navegue até a pasta do projeto:
```
cd ~/projeto/programa
```

8. Compile e execute o projeto usando o Makefile:
```
make run
```