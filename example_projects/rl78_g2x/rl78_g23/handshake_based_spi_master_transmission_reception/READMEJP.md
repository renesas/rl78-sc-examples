# RL78/G23 ハンドシェイク対応 SPI マスタ送受信

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、シリアル・アレイ・ユニット (SAU) による簡易SPI (CSI) のマスタ送受信の使用方法を説明します。チップセレクト (CS) 信号を使用し、1 つのスレーブを選択してシングル送受信を行います。さらに、BUSY 信号を使用し、ハンドシェイクを行います。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.10.00 |
| e2 studio | V2023-10 (23.10.0) |
| CC-RL | V1.12.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1 |
| Smart Configurator | V1.8.0 |
| BSP | V1.30 |

## ハードウェア構成
- RL78/G23-64p Fast Prototyping Board (RTK7RLG230CLG000BJ)

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 ハンドシェイク対応 SPI マスタ送受信](https://www.renesas.com/ja/document/apn/rl78g23-handshake-based-spi-master-transmissionreception-rev101)
