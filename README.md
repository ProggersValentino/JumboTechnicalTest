# Lottery Scoring

Jumbo Interactive Technical Test

# Building

## Docker
This project supports docker

### Prerequisites
- docker v26.0.0 or above
- docker desktop installed
- bash terminal

### Instructions
1. clone project 
```bash
git clone https://github.com/ProggersValentino/JumboTechnicalTest.git
```
2. open bash into project location 

3. build the project into an image by running:
```bash
docker build -t cmake-app .
``` 

4. Go back to docker desktop and run the `cmake-app:latest` image which should output

```
2026-09-30 14:29:41 Mary wins Division 1, with matches 7, 22, 24, 31, 33, 40 for game 7, 22, 24, 31, 33, 40
2026-09-30 14:29:41 
2026-09-30 14:29:41 John wins Division 4, with matches 7, 33, 40 for game 7, 9, 13, 24, 33, 40
2026-09-30 14:29:41 
```