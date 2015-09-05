$(function() {

  $('#submit').on('click', function(e) {
    e.preventDefault()

    var val = $(".options input[type='radio']:checked").val()

    $.ajax({
      url: '/cook',
      type: 'POST',
      data: {
        status: val
      },
      success: function() {
        if (val === 'on') {
          $('.keep-warm').addClass('inactive')
          $('.cooking').removeClass('inactive')
        } else {
          $('.keep-warm').removeClass('inactive')
          $('.cooking').addClass('inactive')
        }
      }
    })
  })
})