#!/bin/bash


for num in $(seq 5) ; do 

echo "# Módulo $num

<!-- @TODO: COMPLETAR  -->
## Referências

[1] TANENBAUM, A. S. Sistemas. Operacionais Modernos. 4ª ed. Prentice Hall, 2016.
" >> "./docs/resumos/mod$num.md" 

echo "  - Módulo $num: resumos/mod$num.md" >> mkdocs.yml

done