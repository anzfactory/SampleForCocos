# SampleForCocos

Sample for Cocos2d (Games)

## description

Cocos2d-x のサンプルプロジェクト  
ライセンスとかはとくにないので、  
きになるものがあれば、ご自由に

使用している、画像や音源素材は  
下記に提供元をのせているので、  
そちらの規約にしたがってください

## cloneのしかた

cocosのソースはサブモジュール化してるので、  
普通にcloneしただけでは空っぽです。

コマンドでcloneする時は`recursive`オプションつけると良い感じなはず

```
  git clone --recursive https://github.com/anzfactory/SampleForCocos.git
```

すでにブラウザからcloneしたりなど、clone済みの場合は  
close先に移動してから、submodule updateでやると良い感じはなず

```
  cd `clone/to/path/SampleForCocos`
  git submodule update --init --recursive
```

SourceTreeでcloneした場合はデフォルトで  
submoduleも引っ張ってくる感じになってるので気にしないで大丈夫  

リポジトリをクローンという画面に**高度なオプション**という箇所があるので、そこで確認可能。  
「サブモジュールを含む」にチェックがついてればok  
逆に外せば、cocosのソースは落ちてこないはず

## サンプル一覧(シーン別)

### MenuSample

Menuのおしっぱ判定サンプル  
`AnzMenu`(Menuを継承したもの)使用

### SoundMenuSample

Menuの一括効果音設定サンプル
`AnzMenu`(Menuを継承したもの)使用

### MenuOffsetSample

MenuのMenuItem達を一括でoffset指定移動  
`AnzMenu`(Menuを継承したもの)使用


## CREDIT

### Powerd by cocos2d-x  
web : [http://www.cocos2d-x.org/](http://www.cocos2d-x.org/)  
git : [https://github.com/cocos2d/cocos2d-x](https://github.com/cocos2d/cocos2d-x)

### cocos source 
サブモジュール化にあたって[kyokomi](https://github.com/kyokomi)さんが`cocos new`で作られるものを  
上げてくださってるので、そちらを利用させてもらってます。  
ありがとうございます！

[cocosNew_cocos2d](https://github.com/kyokomi/cocosNew_cocos2d)

### Music, Sound Effect

[SKIPMORE](http://www.skipmore.com/)
