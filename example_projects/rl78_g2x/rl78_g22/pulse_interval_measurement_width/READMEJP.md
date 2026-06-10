# RL78/G22 タイマ・アレイ・ユニット (パルス間隔測定: 幅)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G22のタイマ・アレイ・ユニット（TAU）を用いたパルス幅測定方法を説明します。TI00端子でパルスの立ち上がり・立ち下がり両エッジを検出し、タイマ値をキャプチャすることでハイレベル幅およびロウレベル幅を測定します。エッジ判定に基づいて測定値を分類し、内蔵RAMに格納します。さらに、動作フローやサンプルコードについて詳しく解説しています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.10.00 |
| e2 studio | V2023-10 (23.10.0) |
| CC-RL | V1.12.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1 |
| Smart Configurator | V1.7.0 |
| BSP | V1.60 |

## ハードウェア構成
- RL78/G22 Fast Prototyping Board
- 外部パルス信号源

## 適用可能デバイス
- RL78/G22

## APNリンク
[RL78/G22 タイマ・アレイ・ユニット (パルス間隔測定: 幅)](https://www.renesas.com/ja/document/apn/rl78g22-timer-array-unit-pulse-interval-measurementwidth-rev102)
