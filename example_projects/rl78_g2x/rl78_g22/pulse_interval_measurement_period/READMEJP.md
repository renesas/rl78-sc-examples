# RL78/G22 シリアル・アレイ・ユニット (UART 通信)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G22のシリアル・アレイ・ユニット（SAU）によるUART通信の使用方法について説明します。対向機器から受信するASCII文字を解析し、適切な応答を返す仕組みを示しています。サンプルコードではUART0を用いた送受信および割り込み処理の実装例を紹介しています。さらに、パリティエラーやフレーミングエラー、オーバランエラーへの対応方法も説明しています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.11.00 |
| e2studio | V2024-04 |
| CC-RL | V1.13.01 |
| IAR | V5.10.1 |
| SC | V1.10.0 |
| BSP | V1.6.2 |

## ハードウェア構成
- RL78/G22-48p Fast Prototyping Board

## 適用可能デバイス
- RL78/G22

## APNリンク
[RL78/G22 シリアル・アレイ・ユニット (UART 通信)](https://www.renesas.com/ja/document/apn/rl78g22-timer-array-unit-pulse-interval-measurementperiod-rev101)
