FROM gcc:latest
WORKDIR /home/appdir
COPY app.cpp .
RUN g++ -o app app.cpp
CMD ["./app"]