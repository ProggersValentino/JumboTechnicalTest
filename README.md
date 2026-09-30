# CMAKE TEMPLATE

initial template for a cmake project with catch2 integrated as the testing engine

# Building

## CMake

## Docker
This project supports docker

### Prerequisites
- docker v26.0.0 or above
- docker desktop installed

### Instructions
1. open docker desktop 

2. build the project into an image by running:
```bash
docker build -t cmake-app .
``` 

To interact with the build apply the following command:
```bash
docker run -it cmake-app:latest
```

From you run the tests and the main executable by running the below commands:

**Tests:**
```bash
./testsExecutable
```

**main executable:**
```bash
./mainExecutable
```

To quit type `exit` in the terminal and it will stop the docker interactive 