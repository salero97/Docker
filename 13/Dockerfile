FROM gcc:latest
RUN apt-get update && apt-get install -y iproute2 net-tools iputils-ping
COPY app.cpp .
RUN g++ -o app app.cpp
EXPOSE 8888
CMD ["./app"]'