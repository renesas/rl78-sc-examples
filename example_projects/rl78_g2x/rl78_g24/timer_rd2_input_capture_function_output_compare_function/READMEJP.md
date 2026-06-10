# RL78/G24 タイマRD2 タイマモード（インプットキャプチャ機能とアウトプットコンペア機能の併用）

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G24のタイマRD2におけるインプットキャプチャ機能とアウトプットコンペア機能の併用方法を説明します。インプットキャプチャ機能では入力波形のパルス幅を測定し、アウトプットコンペア機能では出力タイミングを制御します。スマート・コンフィグレータを活用しつつ、ユーザコードで両機能を組み合わせる手法を示します。設定方法や動作例、サンプルコードが提供されています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.10.00 |
| e2 studio | 2023-07 (23.7.0) |
| CC-RL | V1.12.01 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V.1.7.0 |
| BSP | V.1.60 |

## ハードウェア構成
- RL78/G24 Fast Prototyping Board (RTK7RLG240C00000BJ)
- LED

## 適用可能デバイス
- RL78/G24

## APNリンク
[RL78/G24 タイマRD2 タイマモード（インプットキャプチャ機能とアウトプットコンペア機能の併用）](https://www.renesas.com/ja/document/apn/rl78g24-timer-rd2-using-input-capture-function-and-output-compare-function-rev100)
