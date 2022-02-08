var app = new Vue({
    el: '#app',
    data: {
      message: null,
      messages: []
    },
    methods: {
      addMessageToMessages() {
          const trimmedMessage = this.message.trim()
          const messageIsNotEmpty = trimmedMessage > 0
          const fireThisFunction = this.messages.push( this.message )
          if( messageIsNotEmpty ) {
              fireThisFunction
          }
      },
      removeMessageFromMessages(messageKey) {
          // const messagetoDelete = this.messages[messageKey]
          const messageExists = messageKey > -1
          if ( messageExists ) {
              this.messages.splice(messageKey, 1);
          }
      }
    }
  })