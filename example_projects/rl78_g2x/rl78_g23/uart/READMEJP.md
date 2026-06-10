# RL78/G23 シリアル・アレイ・ユニット (UART 通信)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23のシリアル・アレイ・ユニット（SAU）を用いたUART通信の方法を説明します。対向機器から受信したASCIIデータを解析し、適切な応答を返す処理を実装しています。正常データだけでなく、パリティ・エラーやフレーミング・エラー、オーバーランなどのエラー処理にも対応しています。また、割り込みベースの送受信制御についても解説しています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.09.00 |
| e2 studio | V2023-01 (23.1.0) |
| CC-RL | V1.12.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | V1.4.0 |
| BSP | V1.30 |

## ハードウェア構成
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 シリアル・アレイ・ユニット (UART 通信)](https://www.renesas.com/ja/document/apn/rl78g23-serial-array-unit-uart-communication-rev110)
