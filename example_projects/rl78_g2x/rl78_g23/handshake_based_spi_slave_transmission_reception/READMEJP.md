# RL78/G23 ハンドシェイク対応SPI スレーブ送受信

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、シリアル・アレイ・ユニット (SAU) による簡易 SPI (CSI) のスレーブ送受信の使用方法を説明します。チップセレクト (CS) 信号で選択されたスレーブは、処理に応じてシングル送受信、シングル送信またはシングル受信を行います。さらに、BUSY 信号を使用し、ハンドシェイクを行います。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.08.00 |
| e2 studio | V2022-07 (22.7.0) |
| CC-RL | V1.11.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | V1.4.0 |
| BSP | V1.30 |

## ハードウェア構成
- RL78/G23-64p Fast Prototyping Board (RTK7RLG230CLG000BJ)

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 ハンドシェイク対応SPI スレーブ送受信](https://www.renesas.com/ja/document/apn/rl78g23-handshake-based-spi-slave-transmissionreception-rev100)
