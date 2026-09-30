#build stage
FROM ubuntu:latest AS build

# dependencies need to configure and build cmake project
RUN apt-get update && apt-get install -y \
build-essential \
cmake \
ninja-build \
git \
&& rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN cmake -B build/ -S . -G Ninja 
RUN cmake --build ./build/

#Runtime state
FROM ubuntu:latest AS final

WORKDIR /app

COPY --from=build /app/build/src .

#CMD ["sh", "-c", "./tests/testsExecutable && ./src/mainExecutable"]
ENTRYPOINT ["./mainExecutable"]
