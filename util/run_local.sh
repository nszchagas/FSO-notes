#!/bin/bash

pipenv run mkdocs serve &disown 
edge "http://localhost:8000"
