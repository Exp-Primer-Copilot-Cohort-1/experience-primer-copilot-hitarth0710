// Define a constructor for the Person object
function Person(firstName, lastName, age) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.age = age;
}

// Add a method to the Person prototype
Person.prototype.getFullName = function() {
    return this.firstName + ' ' + this.lastName;
}

// Add another method
Person.prototype.canVote = function() {
    return this.age >= 18;
}

// Create a new Person object
var person = new Person('John', 'Doe', 20);

// Call the methods
console.log(person.getFullName());  // Outputs: "John Doe"
console.log(person.canVote());  // Outputs: true