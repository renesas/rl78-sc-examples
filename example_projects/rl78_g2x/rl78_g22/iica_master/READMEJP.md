# RL78/G22 シリアル・インターフェース IICA (マスタ送受信)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、シリアル・インタフェースIICAによるマスタ送受信機能の使用方法を説明します。シングルマスタ構成でアドレス送信およびデータ送受信を行う方法を示します。マスタはスレーブアドレスを指定して通信を確立し、データの送受信を実行します。サンプルコードおよび動作確認条件も記載されています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.11.00 |
| e2 studio | V2024-04 |
| CC-RL | V1.13.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1 |
| Smart Configurator | V1.10.0 |
| BSP | V1.6.2 |

## ハードウェア構成
- RL78/G22-48ピンファストプロトタイピングボード
- ステータス表示LED
- エラー表示LED
- スイッチ

## 適用可能デバイス
- RL78/G22

## APNリンク
[RL78/G22 シリアル・インターフェース IICA (マスタ送受信)](https://www.renesas.com/ja/document/apn/rl78g22-serial-interface-iica-master-transmissionreception-rev100)
