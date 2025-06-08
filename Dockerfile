FROM debian:bullseye

ENV DEBIAN_FRONTEND=noninteractive

# 必要パッケージのインストールとロケール設定
RUN apt-get update && \
    apt-get install -y \
        bash \
        build-essential \
        gcc-multilib \
        libc6-dev-i386 \
        nasm \
        locales && \
    sed -i 's/^# \(ja_JP.UTF-8\)/\1/' /etc/locale.gen && \
    locale-gen && \
    update-locale LANG=ja_JP.UTF-8 && \
    rm -rf /var/lib/apt/lists/*

# ロケール環境変数をデフォルトで設定（シェル内でも有効）
ENV LANG=ja_JP.UTF-8 \
    LANGUAGE=ja_JP:ja \
    LC_ALL=ja_JP.UTF-8

# 作業ディレクトリ
WORKDIR /scripts

# デフォルトのコンテナ動作（常に起動状態）
CMD ["tail", "-f", "/dev/null"]
