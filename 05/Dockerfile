FROM gcc:latest
RUN apt-get update && apt-get install -y libcurl4-openssl-dev
COPY app.cpp .
RUN g++ -o app app.cpp -lcurl
CMD ["./app"]
