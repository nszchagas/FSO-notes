#!/bin/bash

echo "# Chapter $1
## References

[1] SILBERSCHATZ A., GALVIN P., GAGNE G. Operating System Concepts, 9th Edition.
" >> "./docs/summaries/ch$1.md" 

echo "  - Chapter $1: summaries/ch$1.md" >> mkdocs.yml