function Node(val, next, random) {
  this.val = val;
  this.next = next;
  this.random = random;
}

// Method1: Hash Table
var copyRandomList = function(head) {
  if(!head) return null;  

  let preHead = new Node(head.val);
  let copyCurr = preHead, orgCurr = head;
  let map = new Map();

  while(orgCurr) {
    if(map.get(orgCurr)) copyCurr.next = map.get(orgCurr);
    else {
      copyCurr.next = new Node(orgCurr.val);
      map.set(orgCurr, copyCurr.next);
    }
    copyCurr = copyCurr.next;

    if(orgCurr.random) {
      if(map.get(orgCurr.random)) copyCurr.random = map.get(orgCurr.random);
      else {
        copyCurr.random = new Node(orgCurr.random.val);
        map.set(orgCurr.random, copyCurr.random);
      }
    }

    orgCurr = orgCurr.next;
  }
  return preHead.next;
};

// Methods: change the orginal nodes
function copyRandomList2(head) {
  if(!head) return null;
  let preHead = new Node(-1);
  let curr = head, copyCurr = preHead;
  let tmp;
  while(curr) {
    copyCurr.next = curr;
    tmp = curr.next;
    copyCurr = new Node(curr.val);
    curr.next = copyCurr;
    curr = tmp;
  }
  let res = preHead.next;
  curr = head;
  while(curr) {
    copyCurr = curr.next;
    copyCurr.random = curr.random ? curr.random.next : null;
    curr = copyCurr.next;
  }
  curr = head, copyCurr = curr.next;
  while(copyCurr.next) {
    curr.next = copyCurr.next;
    curr = curr.next;
    copyCurr.next = curr.next;
    copyCurr = copyCurr.next;
  }
  curr.next = null;


  return res;
}


// utils
function makeRandomList(arr) {
  const nodeList = [];
  let head = new Node(0);
  let curr = head;
  arr.forEach(([val, random], idx) => {
    curr.next = new Node(val);
    nodeList.push(curr.next);
    curr = curr.next;
  })
  arr.forEach(([val, random], idx) => {
    if(random !== null) {
      nodeList[idx].random = nodeList[random];
    }
  })
  return head.next;
}

function randomList2Array(head) {
  let curr = head;
  let nodeIdxMap = new Map();
  let arr = []
  let idx = 0;
  while(curr) {
    arr.push([curr.val, null]);
    nodeIdxMap.set(curr, idx);
    idx++;
    curr = curr.next;
  }
  idx = 0;
  curr = head;
  while(curr) {
    if(curr.random !== undefined && curr.random !== null) {
      arr[idx][1] = nodeIdxMap.get(curr.random);
    }
    idx++;
    curr = curr.next;
  }
  return arr;
}

let arr = [[7,null],[13,0],[11,4],[10,2],[1,0]];
let randomList = makeRandomList(arr);
let randomArr = randomList2Array(randomList);
let copyList = copyRandomList2(randomList);
let copyArr = randomList2Array(copyList);

console.log(randomArr);
console.log(copyArr);