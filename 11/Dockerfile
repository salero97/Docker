FROM gcc:latest
COPY app.cpp .
RUN g++ -o app app.cpp
EXPOSE 8080
CMD ["./app"]
