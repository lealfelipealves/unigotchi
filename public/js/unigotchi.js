/* firebase.database().ref('users').set({
  username: 'aha',
  email: 'uhu',
});


const commentsRef = firebase.database().ref(`users/${postId}`);

commentsRef.on('child_added', (data) => {
  addCommentElement(postElement, data.key, data.val().text, data.val().author);
});
*/
