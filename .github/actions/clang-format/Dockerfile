FROM unibeautify/clang-format:latest

# We need python to use run-clang-format.py
RUN apk add --update python

RUN clang-format --version
RUN clang-format --help

COPY entrypoint.sh /
ENTRYPOINT [ "/entrypoint.sh" ]
