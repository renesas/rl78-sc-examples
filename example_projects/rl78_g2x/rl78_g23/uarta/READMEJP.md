# RL78/G23 シリアル・インタフェース UARTA

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、シリアル・インタフェースUARTAを用いたUART通信の方法を説明します。対向機器から受信したASCII文字を解析し、対応する応答データを送信する処理を実装しています。正常通信だけでなく、各種エラー発生時の応答処理にも対応しています。受信・送信・エラー処理は割り込みベースで動作します。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.05.00 |
| e2 studio | V2021-04 (21.4.0) |
| CC-RL | V1.10.00 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V1.0.1 |
| BSP | V1.00 |

## ハードウェア構成
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 シリアル・インタフェース UARTA](https://www.renesas.com/ja/document/apn/rl78g23-serial-interface-uarta)
