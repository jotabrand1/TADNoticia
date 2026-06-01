📰 Sistema de Gerenciamento de Notícias em C
Sistema desenvolvido como projeto prático da graduação para aplicar conceitos de Estruturas de Dados e TAD (Tipo Abstrato de Dados) utilizando a linguagem C.

📌 Sobre o Projeto
O sistema permite cadastrar, classificar e gerenciar notícias em duas filas distintas:

Lista de Pendentes — notícias aguardando verificação (lista com cabeça e cauda)
Lista de Verificadas — notícias já classificadas como confiáveis ou suspeitas (lista encadeada simples)


⚙️ Funcionalidades

✅ Adicionar nova notícia com ID gerado automaticamente
✅ Remover notícia pendente por ID
✅ Remover notícia verificada por palavra-chave
✅ Buscar notícias pendentes por palavra-chave
✅ Classificar notícias (Em Análise / Confiável / Suspeita)
✅ Exibir todas as notícias por categoria
✅ Contar notícias por categoria


🗂️ Estrutura do Projeto
.
├── main.c              # Ponto de entrada e menu interativo
├── Noticia.c/.h        # TAD Noticia (definição e operações)
├── ListaCabCau.c/.h    # Lista encadeada com cabeça e cauda (pendentes)
├── ListaEncadeada.c/.h # Lista encadeada simples (verificadas)
└── Makefile            # Build automatizado

🚀 Como Compilar e Executar
Pré-requisitos

GCC instalado
Linux, WSL ou macOS

Comandos
bash# Clonar o repositório
git clone https://github.com/seu-usuario/sistema-noticias-c.git
cd sistema-noticias-c

# Compilar
make

# Executar
./prog

# Limpar arquivos gerados
make clean

🧠 Conceitos Aplicados
ConceitoDescriçãoTADSeparação entre interface (.h) e implementação (.c)Listas EncadeadasDuas estruturas com propósitos distintosAlocação DinâmicaUso de malloc e free com tratamento de errosProgramação DefensivaValidação de ponteiros e prevenção de memory leaksMakefileCompilação modular e automatizada

📚 Disciplina
Desenvolvido na disciplina de Estrutura de Dados — Graduação em Ciência da Computação
