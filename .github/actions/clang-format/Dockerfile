FROM unibeautify/clang-format:latest

RUN clang-format --version
RUN clang-format --help

COPY entrypoint.sh /
ENTRYPOINT [ "/entrypoint.sh" ]
