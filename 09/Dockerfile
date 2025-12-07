FROM gcc:latest
WORKDIR /
COPY app.cpp .
RUN g++ -o app app.cpp
RUN mkdir -p /home/filedir /home/otherfiledir
ENTRYPOINT ["./app"]
