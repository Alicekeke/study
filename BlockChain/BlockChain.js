/**
 * 区块组成
 * data
 * 之前区块的哈希值
 * 自己的哈希值：由存储在区块里的信息算出来的(data + 之前区块的哈希值)
 */
//  引用crypto-js加密库, 用sha256算它的哈希值
const sha256 = require('crypto-js/sha256')
 
 class Block{
   constructor(data, previousHash) {
     this.data = data
     this.previousHash = previousHash
     this.hash = this.computedHash()
   }
  computedHash () {
    return sha256(this.data + this.previousHash ).toString()
  }
 }

// 链 的数据结构
class Chain {
  constructor() {
    // 数组存储
    this.chain = [this.oldBlock()]
  }
  // 生成祖先区块
  oldBlock() {
    const genesisBlock = new Block('我是祖先区块', '')
    return genesisBlock
  }
  // 最近区块
  getLastBlock () {
    return this.chain[this.chain.length - 1]
  }
  // 添加区块到区块链上
  addBlockToChain( newBlock) {
    // 找到最近一个block的hash 那么该区块的hash就是新区块的previousHash
    newBlock.previousHash = this.getLastBlock().hash
    newBlock.hash = newBlock.computedHash()
    this.chain.push(newBlock)
  }


// 哈希是区块的指纹 验证当前数据是否被篡改
// 验证合法性 -> 验证previousHash是否等于previous区块的hash
  validateChain() {
    if(this.chain.length === 1){
     if( this.chain[0].hash !== this.chain[0].computedHash ) {
       return false
     }
      return true
    }
    
  for (let i = 1; i < this.chain.length - 1; i++){
    const blockToValidate = this.chain[i]
    // 验真当前区块数据有无被篡改
    if( blockToValidate.hash !== blockToValidate.computedHash()) {
      console.log('数据篡改')
      return false
    }
    // 验证previousHash是否等于previous区块的hash
    const previousBlock = this.chain[i-1]
    if (blockToValidate.previousHash !== previousBlock.computedHash()) {
      console.log('前后区块链接断裂')
      return false
    }
  }
  return true
  }

}

const myChain = new Chain()
console.log(myChain);
const block1 = new Block('block1')
myChain.addBlockToChain(block1)
console.log(myChain);

// just proof of concept 
// 概念演示 