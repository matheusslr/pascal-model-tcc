# 📊 pascal-model-tcc

Este repositório documenta os **experimentos, códigos e resultados** desenvolvidos no meu Trabalho de Conclusão de Curso (TCC), cujo objetivo foi a implementação e avaliação de um **modelo de regressão denominado Pascal Regression Model**, com foco na análise de acurácia e comportamento dos erros preditivos.

O repositório tem caráter **acadêmico e experimental**, servindo como apoio à reprodução dos experimentos e à compreensão dos resultados apresentados no trabalho.

---

## 🎓 Contexto Acadêmico

* **Trabalho de Conclusão de Curso (TCC)** – UFRN
* Área: Modelagem / Regressão / Análise de Dados / Análise de escalabilidade / Aplicações paralelas

Este repositório não contém o texto do TCC em si, mas sim os **artefatos computacionais** utilizados durante o desenvolvimento da pesquisa.

---

## 🧠 Objetivo do Repositório

* Centralizar os **notebooks de experimentação** utilizados no TCC;
* Disponibilizar os **datasets processados**;
* Registrar as **visualizações e resultados obtidos**;
* Facilitar a **reprodutibilidade dos experimentos**;
* Servir como documentação técnica do trabalho desenvolvido.

---

## 📁 Estrutura do Repositório

```
pascal-model-tcc/
├── dataset/
│   └── Conjuntos de dados do PARSEC Benchmark utilizados para avaliar a generalização e performance do modelo
├── figures/
│   └── Gráficos e imagens geradas a partir dos resultados
├── runs/
│   ├── Resultados de execuções e experimentos
│   │   └── Cada subdiretório representa um algoritmo avaliado
│   │       ├── sp/
│   │       │   └── Execuções realizadas no supercomputador da UFRN
│   │       └── Arquivos na raiz: execuções realizadas em ambiente local
│   └── Resultados de execuções e experimentos
├── referencias_bibliograficas/
│   └── Materiais e referências utilizadas no trabalho
├── preprocessing.ipynb
├── data_segregation.ipynb
├── data_visualization.ipynb
├── preprocessing_visualization.ipynb
├── train.ipynb
├── results_visualization.ipynb
├── requeriments.txt
├── README.md
└── LICENSE
```

---

## 📓 Descrição dos Notebooks

* **preprocessing.ipynb**
  Responsável pela limpeza, tratamento e preparação inicial dos dados.

* **data_segregation.ipynb**
  Realiza a separação dos dados em conjuntos de treino, validação e teste.

* **data_visualization.ipynb**
  Exploração visual dos dados brutos e transformados.

* **preprocessing_visualization.ipynb**
  Visualizações específicas relacionadas às etapas de pré-processamento.

* **train.ipynb**
  Implementação do treinamento do modelo Pascal e avaliação de desempenho.

* **results_visualization.ipynb**
  Consolidação dos resultados finais, gráficos comparativos e análises de erro.

---

## 🧪 Resultados e Execuções Experimentais

Os resultados experimentais estão organizados principalmente no diretório `runs/`, que contém as evidências empíricas utilizadas para sustentar as análises do TCC.

### Organização das execuções

* Cada subpasta em `runs/` corresponde a um **algoritmo ou abordagem avaliada**;
* A pasta **`sp/`** presente em cada algoritmo refere-se às **execuções realizadas no supercomputador da UFRN**;
* Os **arquivos localizados diretamente na raiz de cada pasta de algoritmo** correspondem às **execuções realizadas em ambiente local**, no computador pessoal do autor.

As figuras e métricas extraídas dessas execuções são consolidadas e analisadas nos notebooks de visualização de resultados.

Os resultados obtidos durante os experimentos incluem:

* Análise comparativa entre valores reais e preditos;
* Avaliação de métricas de erro e acurácia;
* Visualização da distribuição dos resíduos;
* Evidências empíricas que sustentam as conclusões do TCC.

As principais figuras utilizadas na análise estão disponíveis no diretório `figures/`.

---

## 📦 Dependências

As principais bibliotecas utilizadas nos experimentos incluem:

* Python 3.x
* numpy
* pandas
* scikit-learn
* matplotlib
* seaborn
* jupyter

A lista completa e versões específicas das dependências estão descritas no arquivo `requeriments.txt`.

---

## ⚙️ Requisitos e Execução

### Instalação das dependências

```bash
pip install -r requeriments.txt
```

### Execução

Após a instalação, os notebooks podem ser executados sequencialmente em um ambiente Jupyter Notebook ou JupyterLab.

---

## 📖 Saiba mais

O texto completo do Trabalho de Conclusão de Curso, contendo a fundamentação teórica, metodologia detalhada, análises e conclusões, está disponível no Repositório Institucional da UFRN:

🔗 **Leitura do TCC:**
[https://repositorio.ufrn.br/server/api/core/bitstreams/4cf85752-41a0-4301-b88a-8e25f8b53635/content](https://repositorio.ufrn.br/server/api/core/bitstreams/4cf85752-41a0-4301-b88a-8e25f8b53635/content)

---

## 📄 Licença

Este projeto está licenciado sob a **MIT License**. Consulte o arquivo `LICENSE` para mais informações.

---

## 👤 Autor

**Matheus Santos**
Trabalho desenvolvido como parte do TCC na Universidade Federal do Rio Grande do Norte (UFRN).

---

> Este repositório tem finalidade acadêmica e de documentação dos experimentos realizados.
