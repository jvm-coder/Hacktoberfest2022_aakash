const user = {
  name: "John",
  age: 30,
  email: "johndoe@example.com",
};

console.log("manual buffer");

setTimeout(() => {
  console.log(user);
}, 2000);

function checkUserAge(age) {
  const promise = new Promise((resolve, reject) => {
    if (age >= 18) {
      resolve("you're an adult");
    } else {
      reject("you're a minor");
    }
  });
  return promise;
}

checkUserAge(user.age)
  .then((resp) => {
    console.log(resp);
  })
  .catch((err) => {
    console.log(err);
  });
