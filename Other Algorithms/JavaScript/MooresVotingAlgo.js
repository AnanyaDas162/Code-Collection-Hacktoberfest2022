// naive solution ---> Brute Force

let arr = [1,5,5,4,4]
let getMajority = function(a){
    for(let i=0;i<a.length;i++)
    {
       let count = 0;
       let val = a[i];
       for(let j=i;j<a.length;j++)
       {
          if(val == a[j])
          count++;
       }
       if(count > (Number)(Math.floor(a.length/2))){
           return val;
       }
   }
}
let c = getMajority(arr);
if(c == undefined) c = null;
console.log(c);

// second approach

let arr = [1,1,5,4,1,0,0]
function majorityElement(a)
{
  let hmap = new Map();
  for(let i=0;i<a.length;i++)
  {   
    //   let count = 1;
      if(!hmap.has(a[i])){
          hmap.set(a[i],1);
      } else {
          let freq = hmap.get(a[i]);
          freq++;
          hmap.set(a[i],freq);
          if(freq > (Number)(a.length /2))
          return a[i]
      }
  }
  return null;

  
}
console.log(majorityElement(arr));
