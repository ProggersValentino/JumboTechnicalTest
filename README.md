# Lottery Scoring

initial template for a cmake project with catch2 integrated as the testing engine

# Building

## Docker
This project supports docker

### Prerequisites
- docker v26.0.0 or above
- docker desktop installed
- bash terminal
- VSCode 

### Instructions
1. clone project 
```bash
git clone https://github.com/ProggersValentino/JumboTechnicalTest.git
```
2. Open project in VSCode or Jetbrains

3. open docker desktop 

4. build the project into an image by running:
```bash
docker build -t cmake-app .
``` 

5. Interact with the build apply the following command:
```bash
docker run -it cmake-app:latest
```
the terminal should now be in the docker container allowing you to execute commands 

6. From there run the main executable:

**main executable:**
```bash
./mainExecutable
```

To quit type `exit` in the terminal and it will stop the docker interactive 